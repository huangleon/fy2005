// ��Ϥ���������Ĺ���	--- By silencer@fy4. workgroup


inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
    set_name("������", ({ "xu wanli", "xu" }) );
	set("gender", "����" );
	set("age", 61);
	set("title", CYN "�㲻����"NOR);
	set("long","
�������˵����ϼ�͵ĵ�ʮ������ȡ�˸���������֣�ѧ�����������ĵأ�
�����ھ�������￪�˸����Ӿ������ص�ͼ����־��ͬʱ��Щ����ѧͽ������
������¼�������顣\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		"obj/item/map_scroll": 100,
	]) );
	
	set("inquiry", ([
	       	"job": 	 	"�����ȱ���֣�����������ž�����ң��Ҹ���ָ��ָ�㡣\n",
	       	"����": 	"�����ȱ���֣�����������ž�����ң��Ҹ���ָ��ָ�㡣\n",
	       	"ͼ����־": 	"�����ͼ����־�������ƣ�����������ž�����ң��Ҹ���ָ��ָ�㡣\n",
	       	"��ͼ": 	"�����ͼ����־�������ƣ�����������ž�����ң��Ҹ���ָ��ָ�㡣\n",
	       	"map": 		"�����ͼ����־�������ƣ�����������ž�����ң��Ҹ���ָ��ָ�㡣\n",
	       	"��������": 	"��ȥ��������������������ž�����ң��Ҹ���ָ��ָ�㡣\n",
         ]) );
		
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
}

void init(){
	add_action("do_vendor_list","list");
	::init();
}

int accept_object(object who, object item) {
	
	int amount;
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei",
		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin" });
	
	string *c_area =  ({"��ɽ","��ɽ","��ɽ","������","����",
				"��ѩɽׯ","ǧ��ɽ","��ƽɽׯ","����ɽ","��Դ��",
				"�½�", "��÷ɽׯ",
			    "����ɽ","̩ɽ","���ɽׯ","��ɽ","ǧ��¥", 
			    "���Ƶ�","������"});
	string arg, room_name, *files;
	int i, n, m, size, reward, exp;
	object room, silver;
	
	if (item->query("id")!= "scroll" || item->query("usage")!="map")
		return 0;
	
	if (!item->query("room_desc"))	{
		if (item->query("destination")=="none") {
			
			if (who->query("timer/xu_map") + 30 > time()) {
				message_vision(CYN"
������˵���Ҳ��Ǹո��㽻����ô����ô���������\n"NOR, who);
				return 0;
			}
						
			if (who->query("combat_exp")> 100000 
				|| QUESTS_D->verify_quest(who,"���ͼ"))
				m = random(sizeof(area));
			else
				m = random(12);
				
			arg = "/d/"+area[m] +"/";
			files= get_dir(arg);
	    	    	n = 6;
	    	    	
	    	    	while(n--) {
	    	    		i = random(sizeof(files));
	    	        	size = sizeof(files[i]);
//	    	        	message_vision("file is "+ files[i] +"\n", who);
	        		if(files[i][(size-2)..size]==".c") {
	  	        		room_name = arg + files[i];
	  	        		room = find_object(room_name);
	  	        		if (!room)
	  	        			room = load_object(room_name);
	  	        		if (!room)	continue;
	  	        		if (!room->query("short")) continue;
	  	        		break;
	  	        	}
	  	        }	
			
			// Very Bad Luck, I can't find any room.
			if (!room) {
				message_vision(CYN"
������ӹ����ᣬ����ë�ʸ�Ҫ��ʣ���С����һ��һ��ī֭���ھ����ϣ�
������һЦ˵����Ǹ��Ǹ�����ž���û�����ˣ��㻹���µ�ô��\n"NOR,who);
				return 1;
			}
					  	        			
	  	        message_vision(CYN"
������ӹ����ᣬ����ë��������д�˼������ֵݻظ�$N˵�����ȥ���ϵĵ�
�㿼��һ������¼�·���������ٻ������ҡ�\n"NOR, who);
			item->set("map_owner", who);
			item->set("destination", room_name);
			item->set("room_name", room->query("short"));
			item->set("area", c_area[m]);
			who->set("timer/xu_map", time());
			return notify_fail("");
		} else
			{
			message_vision(CYN"
������˵�����Ҳ����Ѿ��Ѿ���ص�д�ھ�������ô����\n"NOR, who);
			return 0;
		}
	} else {
		if (item->query("map_owner")!= who) {
			message_vision(CYN"
������˵�����Һ���û�͸��´�������ɣ�\n"NOR, who);
			return 0;
		}
		message_vision(CYN"
������˵�����ã��ã�̫лл���ˣ�\n"NOR, who);
		// Giving reward
		
		if ( QUESTS_D->verify_quest(who,"���ͼ")){
			amount = 20;
			QUESTS_D->special_reward(who,"���ͼ");
		} else 
			amount = 12;
		
		silver = new("obj/money/silver");
		silver ->set_amount(amount);
		if (!silver->move(who)) 
			destruct(silver);
		tell_object(who, WHT"��õ���"+ chinese_number(amount)+ "�����ӣ���\n"NOR);	
		
		return 1;		
	}	
}



void reset()
{
	set("vendor_goods", ([
		"obj/item/map_scroll": 100,
	]) );
}
		
