#include <dangerzone.pb.h>
#include <google/protobuf/timestamp.pb.h>
#include "DangerZoneSerializer.h"

zmq::message_t DangerZoneSerializer::serializeToZmq(const std::vector<DangerZone> &dangerZones) {
    sailbot::DangerZones dangerZonesSerialized;
    for (const DangerZone &dangerZone : dangerZones) {
        //Gets a pointer to a new DangerZone element as per protobuf documentation
        sailbot::DangerZone *protoDangerZone = dangerZonesSerialized.add_danger_zone();
        protoDangerZone->set_port_angle(dangerZone.getPortAngleDeg());
        protoDangerZone->set_starboard_angle(dangerZone.getStarboardAngleDeg());
        protoDangerZone->set_latitude(dangerZone.get_latitude());
        protoDangerZone->set_longitude(dangerZone.get_longitude());

        ::google::protobuf::Timestamp* timestamp = new ::google::protobuf::Timestamp();
        timestamp->set_seconds(dangerZone.getTime().count());
        protoDangerZone->set_allocated_time(timestamp);
    }

    std::string zmqMessageString;
    dangerZonesSerialized.SerializeToString(&zmqMessageString);
    zmq::message_t message(zmqMessageString.c_str(), zmqMessageString.size());

    return message;
}

