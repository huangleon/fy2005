// help.c  -- by Silencer@fengyun workgroup

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string *default_search = DEFAULT_SEARCH_PATHS;

void selete_main(string num,object ob, string file);
void back_off(string num, object ob, string file);
void quit_help(object ob);

string *game = ({ "questing", "tasking", "riddle","ability","pfm_r1",
					"marry",	"selfroom", "selfmade","death","poison", 
					"settings", "color","level", "books", "questbuff","boss",
					"questbox", "ccard", "ccard", "ccard", "ccard", "scroll",
				 });
string *cmds = ({ "cmds_1", "cmds_2", "cmds_3","cmds_4", "cmds_5", "cmds_6","cmds_7","cmds_8"});
string *newbie = ({ "newbie_1", "newbie_2","newbie_3","newbie_4","newbie_5","newbie_6","newbie_7",
				"newbie_8","newbie_9","newbie_10","newbie_11","newbie_12","newbie_13","newbie_14"});
string *rules = ({ "copyright", "rules", "people" });
string *menpai = ({ "chaoting", "gaibang", "wudang", "huashan", "wolfmount",
			"shaolin", "dazhaosi", "xingguo","diwanggu", 
			"kuaihuo", "sanqing", "shenshui", "haoyue",
			 "tiexue", "fugui",
			"mojiao", "bianfu", "baiyun", "jinqian","wanmei","shenjian", "tianfeng",
			"others",
			 });

string *maps = ({
"map.txt",
"fengyun_map.txt","biancheng_map.txt","chenxiang_map.txt","guanwai_map.txt", 
"jinan_map.txt", "laowu_map.txt","loulan_map.txt", "qianjin_map.txt","taiping_map.txt", 
"taoyuan_map.txt",

 "huashan_map.txt","huangshan_map.txt","kunlun_map.txt","manglin_map.txt","qianfo_map.txt",
 "sanqing_map.txt", "songshan_map.txt", "taishan_map.txt", "wolfmount_map.txt", "wudang_map.txt",
 "shaolin_map.txt", "daimiao_map.txt",

"diwanggu_map.txt", "ehu_map.txt","heisong_map.txt","laoyun_map.txt", "shenshui_map.txt",
"dixia_map.txt","fugui_map.txt","qingping_map.txt","tianfeng_map.txt","tiexue_map.txt",
 "wanmei_map.txt","youling_map.txt",

"baiyun_map.txt", "bat_map.txt","changchun_map.txt",

"east_map.txt","west_map.txt","wulapo_map.txt","zangbei_map.txt","diyu_map.txt",
"cyan_map.txt","xiangsi_map.txt","bashan_map.txt",
});

string *quest = ({
"fengyun.txt","chenxiang.txt","heisong.txt","diwanggu.txt",
"taoyuan.txt", "wudang.txt", "xingguo.txt", "jixiang.txt",
"fugui.txt","guanwai.txt","laowu.txt","wanmei.txt",
"qingping.txt","qianjin.txt","wolfmount.txt","taishan.txt",
"huashan.txt","huangshan.txt","shaolin.txt","changchun.txt",
"ehugang.txt","donghai.txt","bat.txt","dixiacheng.txt",
"taiping.txt","erlangshan.txt","zangbei.txt","eren.txt",
"xiangsi.txt","mingxia.txt","baiyun.txt","daimiao.txt",
"shenshui.txt","saikou.txt","biancheng.txt","sanqing.txt",
"mojiao.txt",
});
   
int main(object me, string arg)
{
        int i;
        string file, map, *search;
        object ob;
        ob = this_player();

	
	if (ob->query_temp("timer/help_list")+1 > time())
		return notify_fail("°ïÖúÏµÍ³ÕıÔÚ»Ö¸´ÖĞ£¬ÇëÔÚÒ»ÃëºóÊ¹ÓÃ¡£\n");
	ob->set_temp("timer/help_list",time());
	
	// Èç¹ûÃ»ÓĞÑ¡Ïî£¬Ìá¹©Ö÷²Ëµ¥¼°Îå¸öÑ¡Ïî¡£
	if( !arg ) {
		write(CLR);
        	write(read_file("/doc/help/help_main"));
        	return 1;
	}

//	£ã£í£ä£ó£¯£î£å£÷£â£é£å£¯£ç£á£í£å£¯£ò£õ£ì£å£ó£¯£í£å£î£ğ£á£é£¯£­£ñ£õ£å£ó£ô²úÉú²Ëµ¥£¬ÆäËû£í£á£ğ£óÖ±½ÓÎÄ¼ş¡£
	
	if (arg == "cmds" || arg == "newbie" || arg == "game" || arg == "rules" || arg == "menpai" || arg == "where"|| arg == "book" || arg == "maps" || arg == "quest" || arg == "road" || arg == "boss" || arg == "boss2" || arg == "boss3" ) {
		write(CLR);
		file = "/doc/help/help_"+arg;
		write(read_file(file));
		input_to("selete_main",ob,file);
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("ÓĞÕâ¸öÖ¸Áî´æÔÚ£¬µ«ÊÇ²¢Ã»ÓĞÏêÏ¸µÄËµÃ÷ÎÄ¼ş¡£\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more("", read_file(search[i] + arg), 0);
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more("", read_file(default_search[i] + arg), 0);
			return 1;
		}
	}

	return notify_fail("Ã»ÓĞÕë¶ÔÕâÏîÖ÷ÌâµÄËµÃ÷ÎÄ¼ş¡£\n");

}

void selete_main (string num, object ob, string file)
{
        
        int number, total;
        string type, *data;
               
        if (ob->query_temp("timer/help_list")+2 > time())
        {
        	ob->add_temp("marks/repeat_help",1);
//        	CHANNEL_D->do_sys_channel(
//				"info",sprintf("%d",ob->query_temp("marks/repeat_help")));
        }	else
        	ob->delete_temp("marks/repeat_help");    
        
        if (ob->query_temp("marks/repeat_help")<4) {
	        ob->set_temp("timer/help_list",time()); 
	        if (sscanf(num,"%d",number)== 1) {
	        	sscanf( file, "/doc/help/help_%s", type);
	        	switch (type) {
	        		case "game": 	data = game; 	break;
	        		case "newbie":  data = newbie;	break;
	        		case "cmds":	data = cmds; 	break;
	        		case "rules":   data = rules;   break;
	        		case "menpai":  data = menpai;  break;
	        		case "maps":	data = maps;	break;
	        		case "quest":	data = quest;	break;
	        		default:	
	        	}
	        	
	        	if (data) {
		        	total = sizeof(data);
		        	if ( number <= total && number) {
		                	write(CLR);
					
		                	if ( type != "menpai") {
		                		write(read_file("/doc/help/"+type+"/"+ data[number-1]));
		                		input_to("back_off",ob, file);	
		                	} else 
		                		ob->start_more("", read_file("/doc/help/"+type+"/"+ data[number-1]+".txt"), 0);
		                	return;
			       	}else if( number == 0) 		{
		    	    	quit_help(ob);
		        		return;	
		        	}
	        	}
	        }
        }  

        ob->delete_temp("marks/repeat_help");    
       	quit_help(ob);
//     	input_to("selete_main", ob, file);
}

void back_off(string num, object ob, string file)
{
	write(CLR);
//      write("file is "+file+"\n");
        write(read_file(file));
        input_to("selete_main", ob, file);
}

void quit_help(object ob)
{
     	write(HIC"\n Ğ»Ğ»Ê¹ÓÃ·çÔÆÃüÁî°ïÖúÏµÍ³£¬½øÒ»²½µÄËµÃ÷¿É²Î¼û¸÷¾ßÌåÃüÁî£¡\n\n"NOR);
        return;
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	help <Ö÷Ìâ>    ÀıÈç£º> £è£å£ì£ğ¡¡£ó£ô£õ£ä£ù[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÌá¹©ÄãÕë¶ÔÄ³Ò»Ö÷ÌâµÄÏêÏ¸ËµÃ÷ÎÄ¼ş£¬

Ïà¹ØÑ¡ÏîÓĞ£º
£è£å£ì£ğ¡¡				Ö÷Ä¿Â¼
£è£å£ì£ğ¡¡£î£å£÷£â£é£å			³õÈë·çÔÆÖ¸ÄÏ
£è£å£ì£ğ¡¡£ã£í£ä£ó			·çÔÆËùÓĞÖ¸Áî»ã±à
£è£å£ì£ğ¡¡£ç£á£í£å			Ïê¾¡½éÉÜÓÎÏ·ÄÚÈİ
£è£å£ì£ğ¡¡£í£å£î£ğ£á£é			·çÔÆÖĞµÄÎä¹¦ÃÅÅÉ
£è£å£ì£ğ¡¡£ò£õ£ì£å£ó			·çÔÆÓÎÏ·¹æÔò
£è£å£ì£ğ¡¡£í£á£ğ£ó			·çÔÆµØÍ¼»ã×Ü
£è£å£ì£ğ¡¡£ñ£õ£å£ó£ô			·çÔÆÈÎÎñ°ïÖú
£è£å£ì£ğ¡¡£¼Ä³Ò»¸ö¾ßÌåÖ¸Áî£¾		¶ÔÄ³Ò»¸öÖ¸ÁîµÄ¾ßÌåËµÃ÷

×¢ÒâÎªÁË¼õÇáÏµÍ³¸ºµ££¬Á¬ĞøÊäÈëµÄÑ¡Ôñ½«²»×ö·´Ó¦¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
	);
	return 1;
}

