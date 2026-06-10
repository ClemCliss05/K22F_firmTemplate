#include "logger.hpp"
#include "ringbuffer.hpp"
#include "uart.hpp"
#include "uart_logger_backend.hpp"

static char log_buffer_memory[256];

static RingBuffer log_buffer(log_buffer_memory, sizeof(log_buffer_memory));

static UartLoggerBackend uart_backend;

static Logger logger(log_buffer, uart_backend);

int main() {
    uart_init();

    LOG_INFO("System boot\n");

    while (1) {
        LOG_DEBUG("loop\n");

        logger.flush();
    }
}