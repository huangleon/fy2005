// ask.c -- by silencer@fy4 9/28/2002

#include <ansi.h>
inherit F_CLEAN_UP;

string in_this_room(object me,string arg);
string look_for_company(object me, object room, string information, int n);
string check_being(object room, string arg, object me);
string *msg_dunno = ({
	"$n¶Ô$NËµµÀ£ºàÅ....ÕâÎÊÌâÄã¿ÉÒÔÎÊÎÊ×Ô¼ºÂğ£¿\n",
	"$n¶Ô$NËµµÀ£º¶Ô²»Æğ£¬Õâ¸öÎÊÌâÄã»¹ÊÇÈ¥ÎÊ±ğÈË°É¡£\n",
	"$nËÊÁËËÊ¼ç£¬ºÜÍïÏ§µØ¶Ô$NËµ£ºÎŞ¿É·î¸æ£¡\n",
	"$n¶Ô$NËµµÀ£ºàÅ....ÕâÎÊÌâµÄ´ğ°¸ÎÒÒªºÃºÃÏëÒ»Ïë¡£\n",
	"$nÕö´óÑÛ¾¦ÍûÖø$N£ºÕâÃ´¼òµ¥µÄÎÊÌâ¶¼ÒªÎÊÂğ£¿\n",
	"$nÒ¡ÁËÒ¡Í·¶Ô$NËµ£ºÎÒ²»ÖªµÀ¡£\n",
	"$nÒ¡ÁËÒ¡Í·¶Ô$NËµ£ºÃ»ÌıËµ¹ı¡£\n",
	"$n³ÁÒ÷ÁËÆ¬¿Ì¶Ô$NËµ£ººÃÏñÓĞµãÓ¡Ïó£¬²»¹ıÔõÃ´Ò²Ïë²»ÆğÀ´ÁË¡£\n",
	"$nÒÉ»óµØ¿´×Å$N,ÏÔÈ»¶Ô$NµÄÎÊÌâÒ»ÎŞËùÖª¡£\n",
});


int main(object me, string arg)
{
	string dest, topic, msg , file_msg, char_name;
	string *chat_msg;
	object ob;
	int i;
	mapping inquiry;

	
	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("ÄãÒªÎÊË­Ê²÷áÊÂ£¿\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");

	if( !ob->is_character() ) {
		message_vision("$N¶ÔÖø$n×ÔÑÔ×ÔÓï....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$NÏò$n´òÌıÓĞ¹Ø¡º" + topic + "¡»µÄÏûÏ¢£¬µ«ÊÇ$pÏÔÈ»Ìı²»¶®ÈË»°¡£\n", me, ob);
		return 1;
	}

	if (me->query_temp("inquiry_time")+1>time()) {
		message_vision("$N¶Ô$nËµ£ºÂıÂıÀ´£¬Ì«¿ìÁËÎÒÌı²»ÇåÄãµÄÎÊÌâ¡£\n"NOR,ob,me);
		return 1;
	}
	
	me->set_temp("inquiry_time",time());
	
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$NÏò$n´òÌıÓĞ¹Ø¡º" + topic + "¡»µÄÏûÏ¢¡£\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		tell_object(me,"µ«ÊÇºÜÏÔÈ»µÄ£¬"+ob->name()+"ÏÖÔÚµÄ×´¿öÃ»ÓĞ°ì·¨¸øÄãÈÎºÎ´ğ¸²¡£\n",
			me, ob);
		return 1;
	}

	if (ob->query("NO_ASK"))
	{
		tell_object(me,ob->query("NO_ASK"));
		return 1;
	}

//	ask for name.
	if(topic == "name" || topic == ob->query("id") || topic == ob->query("name")){
		message_vision("$nËµµÀ£º$n¾ÍÊÇÎÒ£¬ÎÒ¾ÍÊÇ$n£¬ÓĞÊ²Ã´ÊÂÃ´£¿\n",me,ob);
		return 1;
	}


//	ask for spouse
        if ( ob->query("marry"))
        if ( topic == ob->query("marry") || topic == ob->query("marry_name")) {
        	message_vision("$nËµµÀ£º"+ob->query("marry_name")+"ÊÇ"+(ob->query("gender") == "Å®ĞÔ" ? "Íâ×Ó":"ÄÚ×Ó")+"£¬ÓĞÊ²Ã´ÊÂÃ´£¿\n",me,ob);
        	return 1;
       	}


//	ask for chat_chance message.
	if(topic == "here"){
		chat_msg = ob->query("chat_msg");
		i = random(sizeof(chat_msg));
		if(sizeof(chat_msg) > 0) {
			if (stringp(chat_msg[i])){
				message_vision(chat_msg[i], me, ob);
				
			} else { 
				message_vision("$nËµµÀ£ºàÅ....Õâ¸öÎÊÌâÂï£¬ÈÃÎÒÏëÒ»ÏÂÏÈ£¡\n", me, ob);
			}
		} else {
			message_vision("$nËµµÀ£ºàÅ£¬ÄãÏë¾ßÌåÎÊÊ²Ã´ÊÂÄØ£¿\n",me,ob);
		}	
		return 1;
	}

//	hijack the old "leave" msg here
	if (topic == "leave" && me->is_apprentice_of(ob))
	{
		message_vision(CYN"$N³ÁÒ÷Ğí¾ÃµÀ£ºÏëÒªÁíÅÊ¸ßÖ¦ÁË¡£¡£ÈË¸÷ÓĞÖ¾£¬²»ÄÜÃãÇ¿£¬²»¹ı¸÷ÃÅ¸÷ÅÉ¶¼ÓĞ
×Ô¼ºÔËÆøÁ·¹¦µÄ·¨ÃÅ£¬³öÁËÊ¦ÃÅ£¬Ô­À´µÄÎä¹¦ÌØ¼¼¶à°ë¾ÍÃ»·¨ÓÃÁË£¬¶øÇÒĞÂÊ¦¸µ
Ò²²»»á¾¡ĞÄ¾¡Á¦µØ½ÌÄã£¨ÅÑÊ¦Ò»´ÎÉÙÑ§20¼¶¼¼ÄÜ£©£¬ºÃºÃÏëÏë°É£¬³öÁËÃÅ¾ÍÃ»ÓĞ
»ØÍ·Â·ÁË¡£\n"NOR, ob);
		return 1;	
	}
	
	if (topic == "ÅÑÊ¦" || topic == "betray" ) {
		if (me->is_apprentice_of(ob))	{
			message_vision("$NËµ£ºÈË¸÷ÓĞÖ¾£¬ÄãÈôÒª×ß£¬ÎÒ²»ÃãÇ¿£¬ÒÔºó¾Í²»ÒªÔÙ»ØÀ´ÁË¡£\n",ob);
			ob->betray_action(me);
			me->set_temp("marks/apprentice_others",1);
		
		} else
			message_vision("$NËµ£ºÄãÓÖ²»ÊÇÎÒµÄÍ½¶ù£¬´ËÊÂÓëÎÒºÎ¸É£¿\n",ob);
		return 1;
	}
	
//	check for specified msg (in NPC) or general msg	(under that area/NPC directory)
	if( msg = ob->query("inquiry/" + topic)) {
		if( stringp(msg)) {
			if (msg[0..5]=="action")  // ÕâÀïÔÊĞíÉèÖÃÒ»¸öÃ»ÓĞ¡°Ä³Ä³Ëµ¡±µÄmsg¡£Õâ¸ömsg±ØĞëÒÔaction´òÍ·¡£
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$NËµµÀ£º" + msg + "\n" NOR, ob);
		}
		return 1;
	}	
	
		
	if( stringp(ob->query_inquiry_msg(topic))) {
		message_vision( CYN "$NËµµÀ£º" + ob->query_inquiry_msg(topic) + "\n" NOR, ob);
		return 1;
	}

//	check for nearby characters --- NPC is aware of his environment

	if (char_name= in_this_room(me,topic)) {
		message_vision(CYN "$N"+CYN"ËµµÀ£º"+char_name+CYN"²»¾ÍÔÚÄãÑÛÇ°Ã´£¿\n"NOR,ob);
		return 1;
	}
	
	if (char_name = look_for_company(me, environment(ob),topic, 3)) {
		message_vision(CYN "$N"+CYN"ËµµÀ£ºàÅ£¬×î½üºÃÏñ¼û¹ı"+char_name+CYN"£¬Ó¦¸Ã¾ÍÔÚ×ó½ü¡£\n"NOR,ob);
		return 1;
	}
	
//	check for general replies	
	if (msg = ob->query("inquiry/" + "*")){
		if (msg[0..5]=="action")  // ÕâÀïÔÊĞíÉèÖÃÒ»¸öÃ»ÓĞ¡°Ä³Ä³Ëµ¡±µÄmsg¡£Õâ¸ömsg±ØĞëÒÔaction´òÍ·¡£
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$NËµµÀ£º" + msg + "\n" NOR, ob);
	} else {
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
	return 1;

}

int help(object me)
{
   write( @HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	ask <Ä³ÈË> about <Ä³ÊÂ>    Ñ¯ÎÊÄ³ÈËÄ³¼şÊÂ  
		ask <Ä³ÈË> about <Ä³ÈË>    Ñ¯ÎÊÄ³ÈËµÄÇé¿ö
		ask <Ä³ÈË> about here      Ñ¯ÎÊÄ³ÈËµÄÁÄÌìĞÅÏ¢[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

µ±Óöµ½Ò»¸öĞÂµÄNPCÊ±£¬Äã¿ÉÒÔÊ¹ÓÃ
ask <Ä³ÈË> about here À´µÃÖªËûµÄÈÕ³£ÁÄÌìĞÅÏ¢»òÆ½Ê±Ëù×÷µÄ¶¯×÷£¬

Èç¹ûÄã¶ÔÕâ¸öNPCµÄ±³¾°ÊìÏ¤µÄ»°£¬¿ÉÒÔÓÃ
ask <Ä³ÈË> about <Ä³ÊÂ> À´µÃÖªËû¶ÔÆäËûÈË/ÆäËûÎï¼şµÄÆÀ¼Û¡£

Èç¹ûÄãÖªµÀÄ³ÈË¾ÍÔÚ¸½½ü£¬µ«Ò»Ê±ÕÒ²»µ½£¬¿ÉÒÔÓÃ
ask <Ä³ÈË> about <Ä³ÈË>   Èç¹ûNPC×î½ü¼û¹ı´ËÈË£¬»á¸øÄãÒ»¶¨ÌáÊ¾¡£

Õâ¸öÖ¸ÁîÔÚ½âÃÕÊ±ºÜÖØÒª£¬Ğí¶àÃÕÌâ¶¼ÊÇÓÉÑ¯ÎÊNPCÄ³¸ö¹Ø¼üÈËÎï»òÎïÆ·
µÄÃû×ÖÀ´´¥·¢µÄ£¬¹Ø¼üÈËÎïÎïÆ·µÄÃû×Ö¾ÍÒª¿´Äã¹Û²ìÁ¦ÊÇ·ñÃôÈñ£¬¶ÔÓĞ¹Ø
¹ÅÁúĞ¡ËµÊÇ·ñÊìÏ¤ÁË¡£
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
   );
   return 1;
}


string in_this_room(object me,string arg) {
	object *inv;
	int i;
	
	inv=all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("id")== arg || inv[i]->query("name")== arg) 
			return inv[i]->query("name");
	}
	return 0;
}


string look_for_company(object me, object room, string information, int n) {

        object *inv, next_room;
	int i;	
	mapping exits;
	string *dirs, dest, id_name;
        
        if( mapp(exits = room->query("exits")) ) 
	{
		dirs=keys(exits);
		for(i=0;i<sizeof(dirs);i++)
		{
			dest=room->query("exits/"+dirs[i]);
			if(!next_room=find_object(dest))
				next_room=load_object(dest);
			if (!objectp(next_room)) continue;
			if (next_room==environment(me)) continue;
			if (next_room->query("summoned")) continue;
			if (!n) continue;
			if (id_name=check_being(next_room, information, me)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}	
			if (id_name=look_for_company(me,next_room,information,n-1)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}
		}
	}
	room->delete("summoned");
	return 0;
}


string check_being(object room, string arg, object me) {
	object *inv;
	int i;
//	tell_object(me,"room is"+ (string)room->query("short")+"\n");
	room->set("summoned",1);
	inv=all_inventory(room);
	if (!sizeof(inv)) return 0;
	for(i=0;i<sizeof(inv);i++){
		if (!inv[i]->is_character()) continue;
		if (inv[i]->query("id")== arg || inv[i]->query("name")==arg) {
			return 	inv[i]->query("name");
		}
	}
	return 0;
}