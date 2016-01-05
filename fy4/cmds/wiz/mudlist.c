// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

#define	SYNTAX	"Ö¸Áî¸ñÊ½£ºmudlist [<Mud Ãû³Æ>]\n"
int num_players(string mudname);
int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("ÍøÂ·¾«Áé²¢Ã»ÓĞ±»ÔØÈë£¬ÇëÏÈ½«ÍøÂ·¾«ÁéÔØÈë¡£\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "Ä¿Ç°²¢Ã»ÓĞ¸úÍøÂ·ÉÏÆäËû Mud È¡µÃÁªÏµ¡£\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "²¢Ã»ÓĞºÍÕâ¸ö Mud È¡µÃÁªÏµ¡£\n");
			return 1;
		}
		printf("ÓĞ¹Ø %s µÄ×ÊÑ¶£º\n%O\n", arg, mud_list[arg]);
		return 1;
	}

	output = "Mud Ãû³Æ\t\t¹ú¼ÊÍøÂ·Î»Ö·\t      ²ººÅ\t   °æ±¾   \tÔÚÏßÈËÊı\n========\t\t============\t      ====\t==========\t========\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-24s%-18s%8s\t%s\t%d\n", muds[loop], 
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			mud_list[muds[loop]]["VERSION"],
		 	num_players(muds[loop])	
			);

	//	Display dumped mudlist output through user's more pager
	this_player()->start_more("", output, 0);

	return 1;
}

int num_players(string mudname)
{
 string f_m_n;
 string file;
 if(mudname == INTERMUD_MUD_NAME) return sizeof(users());
 f_m_n = REMOTE_DIR+"id@"+mudname;
 if(file_size(f_m_n) <=0) return 0;
 file = read_file(f_m_n);
 if(!stringp(file)) return 0;
 file = replace_string(file,"\n","");
 return sizeof(explode(file, " "));
}


int help(object me)
{
  write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	mudlist[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄãÁĞ³öÄ¿Ç°¸úÕâ¸ö Mud ÁªÏµÖĞµÄÆäËû Mud¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
    );
    return 1;
}
