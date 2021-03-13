from conans import ConanFile, CMake, tools


class LsStdConan(ConanFile):
    name = "ls-std"
    version = "2021.1.0"
    license = "MIT"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "This library provides standard functionalities like serialization, json, xml, file operations, boxing, state machine, event handling."
    topics = ("serialization", "events", "boxing", "xml", "json", "files", "state machine")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"

    def source(self):
        self.run("git clone https://vcs.lynarstudios.de/public/ls-standard-library.git")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="ls-standard-library")
        cmake.build()

    def package(self):
        self.copy("*.hpp", dst="include", src="ls-standard-library/include")
        self.copy("*ls_std_2021.1.0_static.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["ls_std_2021.1.0_static"]
