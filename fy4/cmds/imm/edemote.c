// edemote.c
#include <ansi.h>
inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
	mapping emote;

	if( !arg ) return notify_fail("ÄãÒª±à¼­Ê²÷á emote£¿\n");

	if( sscanf(arg, "-d %s", arg) ) {
		write("É¾³ý emote£º" + arg + "\n");
		CHANNEL_D->delete_emote(arg);
		return 1;
	}

	if( sscanf(arg, "-p %s", arg) ) {
		emote = CHANNEL_D->query_emote(arg);
		printf("ÉÏ´ÎÐÞ¸Ä£º%s\n", emote["updated"]);
		printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			emote["myself"], emote["others"], emote["myself_self"],
			emote["others_self"], emote["myself_target"], emote["target"],
			emote["others_target"] );
		return 1;
	}

	emote = CHANNEL_D->query_emote(arg);
	emote = (["updated":geteuid(me)]);

	write("±à¼­ emote£º" + arg + "\n");
	write("Ñ¶Ï¢¿ÉÒÔÓÐºÃ¼¸ÐÐ£¬ÓÃ . ±íÊ¾½áÊø¡£\n");
	write("Ñ¶Ï¢ÖÐ¿ÉÊ¹ÓÃµÄ²ÎÊýÓÐÒÔÏÂ¼¸ÖÖ£º\n");
	write("  $N  ×Ô¼ºµÄÃû×Ö¡£\n");
	write("  $n  Ê¹ÓÃ¶ÔÏóµÄÃû×Ö¡£\n");
	write("  $P  ×Ô¼ºµÄÈË³Æ´úÃû´Ê£¬ÈçÄã¡¢ÎÒ¡¢Ëû¡¢Ëý¡¢Ëü¡¢Ëü¡£\n");
	write("  $p  Ê¹ÓÃ¶ÔÏóµÄÈË³Æ´úÃû´Ê£¬ÈçÄã¡¢ÎÒ¡¢Ëû¡¢Ëý¡¢Ëü¡¢Ëü¡£\n");

	write("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	write("²»Ö¸¶¨¶ÔÏóÊ¹ÓÃÕâ¸ö emote Ê±£¬Äã×Ô¼º¿´µ½µÄÑ¶Ï¢£º\n->");
	input_to("get_msg_myself", emote, arg);
	return 1;
}

string getincolor(string emote)
{
      emote = replace_string(emote, "$BLK$", BLK);
      emote = replace_string(emote, "$RED$", RED);
      emote = replace_string(emote, "$GRN$", GRN);
      emote = replace_string(emote, "$YEL$", YEL);
      emote = replace_string(emote, "$BLU$", BLU);
      emote = replace_string(emote, "$MAG$", MAG);
      emote = replace_string(emote, "$CYN$", CYN);
      emote = replace_string(emote, "$WHT$", WHT);
      emote = replace_string(emote, "$HIR$", HIR);
      emote = replace_string(emote, "$HIG$", HIG);
      emote = replace_string(emote, "$HIY$", HIY);
      emote = replace_string(emote, "$HIB$", HIB);
      emote = replace_string(emote, "$HIM$", HIM);
      emote = replace_string(emote, "$HIC$", HIC);
      emote = replace_string(emote, "$HIW$", HIW);
      emote = replace_string(emote, "$NOR$", NOR);
	return emote;
}
int get_msg_myself(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself"]) )
		{
		emote["myself"] = getincolor(emote["myself"]);
		emote["myself"] += "\n";
		}
		write("²»Ö¸¶¨¶ÔÏóÊ¹ÓÃÕâ¸ö emote Ê±£¬ÆäËûÈË¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_others", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself"]) )
		emote["myself"] += msg + "\n";
	else emote["myself"] = msg;
	write("->");
	input_to("get_msg_myself", emote, pattern);
	return 1;
}

int get_msg_others(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others"]) )
                {
                emote["others"] = getincolor(emote["others"]);
                emote["others"] += "\n";
                }
		write("¶Ô×Ô¼ºÊ¹ÓÃÕâ¸ö emote Ê±£¬×Ô¼º¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_myself_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others"]) )
		emote["others"] += msg + "\n";
	else emote["others"] = msg;
	write("->");
	input_to("get_msg_others", emote, pattern);
	return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_self"]) )
                {
                emote["myself_self"] = getincolor(emote["myself_self"]);
                emote["myself_self"] += "\n";
                }
		write("¶Ô×Ô¼ºÊ¹ÓÃÕâ¸ö emote Ê±£¬ÆäËûÈË¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_others_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_self"]) )
		emote["myself_self"] += msg + "\n";
	else emote["myself_self"] = msg;
	write("->");
	input_to("get_msg_myself_self", emote, pattern);
	return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_self"]) )
                {
                emote["others_self"] = getincolor(emote["others_self"]);
                emote["others_self"] += "\n";
                }
		write("¶Ô±ðÈËÊ¹ÓÃÕâ¸ö emote Ê±£¬×Ô¼º¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_myself_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others_self"]) )
		emote["others_self"] += msg + "\n";
	else emote["others_self"] = msg;
	write("->");
	input_to("get_msg_others_self", emote, pattern);
	return 1;
}

int get_msg_myself_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_target"]) )
                {
                emote["myself_target"] = getincolor(emote["myself_target"]);
                emote["myself_target"] += "\n";
                }
		write("¶Ô±ðÈËÊ¹ÓÃÕâ¸ö emote Ê±£¬Ê¹ÓÃ¶ÔÏó¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_target"]) )
		emote["myself_target"] += msg + "\n";
	else emote["myself_target"] = msg;
	write("->");
	input_to("get_msg_myself_target", emote, pattern);
	return 1;
}

int get_msg_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["target"]) )
                {
                emote["target"] = getincolor(emote["target"]);
                emote["target"] += "\n";
                }
		write("¶Ô±ðÈËÊ¹ÓÃÕâ¸ö emote Ê±£¬³ýÄã×Ô¼ººÍÊ¹ÓÃ¶ÔÏóÍâ£¬ÆäËûÈË¿´µ½µÄÑ¶Ï¢£º\n->");
		input_to("get_msg_others_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["target"]) )
		emote["target"] += msg + "\n";
	else emote["target"] = msg;
	write("->");
	input_to("get_msg_target", emote, pattern);
	return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_target"]) )
                {
                emote["others_target"] = getincolor(emote["others_target"]);
                emote["others_target"] += "\n";
                }
		CHANNEL_D->set_emote(pattern, emote);
		write("Emote ±à¼­½áÊø¡£\n");
		return 1;
	}
	if( !undefinedp(emote["others_target"]) )
		emote["others_target"] += msg + "\n";
	else emote["others_target"] = msg;
	write("->");
	input_to("get_msg_others_target", emote, pattern);
	return 1;
}

int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	edemote [-d|-p] <emote>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¿ÉÒÔÐÞ¸Ä, É¾³ý emote »òÁÐ³öÆäÄÚÈÝ. ¼ÓÉÏ -d ²ÎÊý»áÉ¾³ý
Ö¸¶¨µÄ emote, -p ²ÎÊýÔò»áÁÐ³öÖ¸¶¨ emote µÄÄÚÈÝ. ÁÐ³öµÄË³ÐòÓë±à
¼­ emote Ê±ÏàÍ¬.

ÊäÈë emote Ñ¶Ï¢Ê±ÓÐÈý¸öÏîÄ¿: Ã»ÓÐÄ¿±ê, Ö¸¶¨Ä¿±ê»òÊÇ¶Ô×Ô¼º. Èô
²»ÏëÓÐÄ³ÏîÑ¶Ï¢, ÔòÖ±½ÓÔÚ¿Õ°×ÐÐÊäÈë '.' Ìø¹ý.

Ò»¸ö emote Ñ¶Ï¢¿ÉÒÔÓÐºÜ¶àÐÐ, ÔÚ¿Õ°×ÐÐÊäÈë '.' ½áÊøÊäÈë¸ÃÏî emote.

±à¼­ emote Ê±¿ÉÒÔÓÃÒÔÏÂµÄ·ûºÅÀ´±íÊ¾:

$N : ×Ô¼ºµÄÃû×Ö.
$n : Ä¿±êµÄÃû×Ö.
$P : ×Ô¼ºµÄÈË³Æ´úÃû´Ê.
$p : Ä¿±êµÄÈË³Æ´úÃû´Ê.
$S : ¶Ô×Ô¼ºµÄ³Æºô¡£
$s : ¶Ô×Ô¼ºµÄ´ÖÂ³³Æºô¡£
$C : ¶Ô×Ô¼ºµÄÄØ³Æ¡£
$c : ¶Ô±ðÈËµÄÄØ³Æ¡£
$R : ¶Ô±ðÈËµÄ×ð³Æ¡£
$r : ¶Ô±ðÈËµÄ´ÖÂ³³Æºô¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
