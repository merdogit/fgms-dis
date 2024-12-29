/**
 * \page FlightGear FlightGear
 * 
 * \section fg_intro The FlightGear Project (fg)
 * 
 *  - <b>FlightGear</b> is the project as a whole
 *    * The FlightGear project is made of many parts, and \ref fgms is one of them
 *      - Wiki:  http://wiki.flightgear.org
 *      - Home:  http://www.flightgear.org
 *      - Code:  https://gitorious.org/fg
 *      - Bugs:  https://code.google.com/p/flightgear-bugs/issues/list
 *      - Build: http://flightgear.simpits.org:8080/ 
 * 
 * \subsection fg_mailing_list FG Mailing List
 * Most developer cummunications is though the mailing list and IRC
 * - http://wiki.flightgear.org/index.php/Mailing_list
 * - http://wiki.flightgear.org/IRC
 * 
 * \subsection fg_contents On this page
 * * \ref fgfs  below is the "command" used to launch the simulator
 * * \ref fgms_for_fgms - at bottom is some extra dev information
 * 
 * \section fgfs fgfs
 * This is an example command line used to launch a sim
 * \code 
 * > fgms --callsign=test1 --multiplay=out,4,mpserver14.flightgear.org,5000 --multiplay=in,4,localhost,5000
 * \endcode
 * The important command line vars for us in \ref fgms land are:
 * \code 
 * --multiplay=out,4,mpserverXX.flightgear.org,5000
 * --multiplay=in,4,server.ip.address,5000
 * \endcode
 * \warning 
 * 		There <b>must be no spaces</b> eg 
 * 		\code 
        --multiplay=in,4, my.server.address ,5000
                     oops ^           oops2 ^
 * 		\endcode
 * 
 * 
 * The <b>--multiplay</b> option is broken down as follows
 * \code 
	--multiplay=[direction],[freq_hz],[host],[port]
	\endcode
 * 
 *  - <b>direction</b> 
 *     - <b>out</b> for sending to an mpserver
 *     - <b>in</b> for recieving from a connection
 *  - <b>freq_hz</b> 
 *     - the number of times a second udp packets are sent
 *     - a high number eg +10 will be bombarding the network
 *     - around 4 frames a second is cool enough
 *     - even lower eg 2 frames a second 
 *  - <b>host</b> 
 *     - for <b>out</b> - this needs to be the server address eg mpserverNN.flightgear.org
 *     - for <b>in</b> - this needs to be your host name or ip eg localhost
 *  - <b>port</b> 
 *     - by default this is 5000
 * 
 * \warning Users were previously encouraged to use 10 hz. This consumes a lot of bandwidth. 
 * This number comes from the time when fgfs was not able to <i>'emulate'</i> a remote aircraft while no data is received. 
 * The first multiplayer versions just updated a remote aircraft's position on data reception 
 * and the aircraft stayed where it was until the next position arrived. 
 * Since then a lot of things have changed, but we never tried to reduce the number of packets. 
 * Its recommended that <b>2 to 4 pps are enough</b>.
 * 
 * @see fgfs Command line options the the FlightGear wiki
 * 			- http://wiki.flightgear.org/Command_line_options#MultiPlayer_Options
 * 
 * 
 * \section fgms_for_fgms Info for fgms developers
 * 
 * Bits of the multiplayer code from flightgear is copied as needed
 *  - See https://gitorious.org/fg/flightgear/trees/next/src/MultiPlayer
 *  - and \ref flightgear_inc
 * 
 * Of interest also is the list of "properties" that are sent. Although
 * these are simply relayed.
 *  - properties: https://gitorious.org/fg/flightgear/blobs/next/src/MultiPlayer/multiplaymgr.cxx#line69
 *  - A ::CHAT_MSG_ID is depreceated, instead its a property
 *    - <b>{10002, "sim/multiplay/chat", simgear::props::STRING}</b>
 * 
 */
