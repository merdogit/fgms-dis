 /**
 * \page tracker FG Tracker
 * 
 * The \ref FlightGear Tracker tracks flights performed on multiplayer server.
 * 
 *  \note 
 *      - Currently there is only one tracking server, hosted by \ref hazuki
 *      - Click here > http://fgtracker.ahven.eu/modules/fgtracker/
 * 
 * - Flights are indexed and stored by their Callsign
 * - The following data is logged
 *     - Start Time
 *     - End Time
 *     - Max altitude
 *     - Aircraft
 *     - Duration
 *     - Total distance
 *     - Max ground speed
 *     - Max Mach
 * 
 * 
 * The Tracker comprises:
 * * <b>\ref tracker_server</b> - a standalone application
 * * <b>\ref tracker_client</b> - embedded in fgms
 * * <b>\ref tracker_protocol</b> - for data interchange
 *
 * \section tracker_protocol Tracker Protocol
 * * There are five types of messages exchanged:
 *   - CONNECT
 *   - POSITION
 *   - DISCONNECT
 *   - PING
 *   - PONG
 * 
 * Originally, the tcp exchange between \ref tracker_client and the \ref tracker_server only 
 * occurred when there was a message to send. This meant it was unknown if the
 * \ref tracker_server was connected until it actually came time to send the message.
 * 
 * The way it was written originally meant messages would be lost. So \ref hazuki introduced the 
 * PING/PONG messages at the same time he added a save so no messages would be lost.
 * 
 * \todo (pete) Expalin messages more
 * 
 * \section tracker_server Tracker Server
 *  - The Tracker server is run as a standalone application, seperate from \ref fgms
 *  - It could be located on another machine on the internet
 *  - It can track more than one mpserver
 *  - The tracker is created as part of the install process, see \ref install_tracker
 * 
 * \subsection tracket_server_dev Dev Info
 * The source code for the tracker server is in the <b>contrib/fgtracker/</b> directory and
 * the application is written is c. (see server.c).
 * 
 * 
 * 
 * \section tracker_client Tracker Client
 * * The client is embedded in \ref fgms itelf (see FG_TRACKER by \ref julien)
 * * The tracker client is configured in \ref tracker_config section of the \ref fgms_conf file
 * 
 * \note
 *     - Only locally attached clients are forwarded to the tracker.
 *     - Pilots connected to fgms with \ref servertracked disabled will
 *      never appear on the tracker.
 * 
 * \subsection tracker_client_dev Dev Info
 *  Internally \ref fgms prepares the messages, and sends them 
 *  - first to an IPC msgsnd (m_ipcid, &buf, ... )
 *  - and are received by FG_TRACKER, msgrcv (ipcid, &buf, ...) 
 *  - then written to the tracker socket - SWRITE( m_TrackerSocket, msg, ... )
 * 
 * The reason for using the unix IPC mechanism was due to 
 * the FG_TRACKER being run in a fork() process, thus does not have 
 * shared memory. Hence the unix msgsnd/msgrcv IPC.
 * 
 * For windows, a FG_TRACKER thread, was introduced by \ref geoff since there is no fork() in windows;
 * a simple vector msg_queue, protected by a mutex is used to pass
 * these messages internally from FG_SERVER to FG_TRACKER.
 * 
 */