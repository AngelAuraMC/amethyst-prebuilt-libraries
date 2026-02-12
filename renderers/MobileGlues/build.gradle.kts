plugins {
    id("com.android.library")
}

android {
    namespace = "com.swung0x48.mobileglues"
    compileSdk = 36

    defaultConfig {
        minSdk = 21

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        consumerProguardFiles("consumer-rules.pro")
        ndkVersion = "27.1.12297006"
    }

    buildTypes {
        getByName("release") {
            isMinifyEnabled = false
            proguardFiles(
                    getDefaultProguardFile("proguard-android-optimize.txt"),
                    "proguard-rules.pro"
            )
        }
        create("proguard") {
            isMinifyEnabled = true
            initWith(getByName("debug"))
        }
        create("fordebug") {
        }
    }
    sourceSets {
        getByName("main") {
            assets.srcDirs("assets")
        }
    }
    externalNativeBuild {
        cmake {
            path = file("MobileGlues/src/main/cpp/CMakeLists.txt")
            version = "3.22.1"
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}