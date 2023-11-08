#ifndef _UID_H_
#define _UID_H_

#include <string>
#include <filesystem>

namespace uid {

/**
 * @brief UID class
 * A class that generates a unique ID and writes it to a JSON file.
 * The class can also read the UID from a JSON file.
 * The format of the JSON file is:
 *      {
 *          "uid": "unique_id"
 *      }
*/
class UID {

public:

    UID() = default;
    ~UID() = default;

    std::string getUID() const;
    void initUID();
    bool writeUIDToFile(const std::filesystem::path& filePath) const;
    bool readUIDFromFile(const std::filesystem::path& filePath);
private:
    std::string m_uid;

    std::string generateRandomStirng(uint32_t strLength) const;
};

}   // namespace uid

#endif // _UID_H_