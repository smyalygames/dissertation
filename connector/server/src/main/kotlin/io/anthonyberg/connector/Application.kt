package io.anthonyberg.connector

import SERVER_PORT
import io.anthonyberg.connector.vdmj.VDMJ
import io.ktor.server.application.*
import io.ktor.server.engine.*
import io.ktor.server.netty.*
import io.ktor.server.response.*
import io.ktor.server.routing.*

fun main() {
    embeddedServer(Netty, port = SERVER_PORT, host = "0.0.0.0", module = Application::module)
        .start(wait = true)
}

fun Application.module() {
    routing {
        get("/") {
            val vdm = VDMJ().run("complete_procedure(\"Before Start\", aircraft)")
            call.respondText("Ktor: $vdm")
        }
    }
}
