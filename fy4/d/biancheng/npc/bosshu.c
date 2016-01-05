#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("���ƹ�",({"hu zhanggui","hu","zhanggui"}));
	set("title","����");
   	set("long","
�����������⣬����һ�Ѵ���ӣ��������̵ĺ��ƹ���Χ��һ���������Χ
ȹ�����ڹ�̨�������⡣���ƹ������ʮ�࣬����ǰ���ڵ����˸����������
ϱ������˵Ů�˿���ȥ�������صģ��½������˺��ӣ����ƹ����������ɹ��
��������᲻�Ƕ���\n");
     	set("gender","����");
    	set("group","citizen");
    	
    	set("combat_exp",3700000);  
    	set("age",42);
    	 	    	 	  	
    	set("inquiry", ([
//	        	"�����嶾"	:		(: kill_him :),
//             	"�ɻ���"	:		(: kill_him :),
   		]));
   	
    	set("death_msg",CYN"\n$N˵�������ģ���������û������û�˵�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"�е��������˰���ǿ����ٵ���������\n",
        ]) );    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"���ƹ�˵�����ú���þƣ��þ�����⣬����������Ϻ�����\n",
			"���ƹ�˵��������ϱ��ʲô���ã����ǰ���Ǯ������Ů�ˡ���������\n",
    	}) );    	    	

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(50) :),
        }) );
    	
    	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
		setup();
    	delete_skill("yijinjing");
    	carry_object("/obj/armor/cloth",([	"name": "�ͼ��߰ߵ�Χȹ",
    						"long": "һ���ͼ��߰ߵ�Χȹ�����滹մ�ŵ��εε���ĩ��\n",
    						 ]))->wear();    
    	
}


void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 		if (this_object()->is_fighting()) {
 			tell_object(me,"���ƹ�����û�ջش��㡣\n");
 			return 1;
 		}
        if(!me->query("marks/wanma/�ײ�֮��")) {
        	tell_object(me,"���ƹ�˵��û��˵����������а���ý���\n");
        	return 1;
        }
        	
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó����������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n",this_object());
        another = new(__DIR__"yunzhonghe");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}


void greeting(object ob)
{
	object hu,blade,groom;
	
	if( !ob || environment(ob) != environment() && is_fighting()) return;
	hu=this_object();
	if (REWARD_D->check_m_success( ob, "����Сϱ��")) {
		message_vision("$Ņͷ��$nһ����ˢ��һ�´Ӽ����ϳ��һ�����λε�ɱ����\n",hu,ob);
		if (!hu->query_temp("weapon")) {
				blade=new(__DIR__"obj/pblade");
				blade->set("value",0);
				blade->move(hu);
				command("wield blade");
		}
		if (ob->query("gender")=="Ů��") {
			command("say Ů�˼Ҳ�ѧ�ã�ȴ����ϱ�����һ�Ǯ�����߿��ߡ�");
		}
		else {
			command("say �󵨣����Һ���ϱ��ü����ȥ�Ĺ������ѵ��һ�²��ɣ�");
			fight_ob(ob);
			ob->fight_ob(hu);
			ob->set_temp("marks/wanma/���ƹ�ɱ",1);
		}
	}
}



void win_enemy(object loser){
    	object groom;
    	
    	command("puke");
 //   	if (!loser->is_busy())
 //   	{
    		groom = find_object(AREA_BIANCHENG"road4");
			if(!objectp(groom)) groom = load_object(AREA_BIANCHENG"road4");
			loser->move(groom);
			loser->delete_temp("marks/wanma/���ƹ�ɱ");
			message_vision(HIY "\n$N��$n���˳�����\n"NOR, loser,this_object());
//		}
}


void lose_enemy(object winner){
    	command("say ��ݣ�������¿�������������ơ�\n");
    	winner->delete_temp("marks/wanma/���ƹ�ɱ");
}
