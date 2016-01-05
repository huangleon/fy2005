#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void look_for_company(object me, object room, int n);
void summon_npc(object me, object next_room);
int kill_him();
int hu();

void create()
{
    	set_name("����ʵ",({"zhang laoshi","zhang","laoshi"}));
	set("title","����ϰ�");
   	set("long","
����ʵ����Ǹ���ʵ�ˣ�����������С��ݵ��ϰ壬Ҳ�ǳ��Ӻͻ�ƣ�
����һ�굽ͷ����������Χ�ſ��������Χȹ��������һֱæ����ڣ�
׬����Ǯȴ�������Ŷ������𡣡�\n");

     	set("gender","����");
    	set("group","citizen");	
    	
    	set("combat_exp",1400000);  
    	set("age",42);
    	   	    	
    	set("inquiry", ([
             	"�����嶾"	:	(: kill_him :),
             	"����"	:		(: kill_him :),
             	"�����":		(: hu :),
             	"������":		(: hu :),	
   	]));
    	
    	
    	set("death_msg",CYN"\n$N�ں޵�˵�����ҿ�����ûϣ��Ȣϱ���ˡ���\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: name()+"�е��������˰���ǿ����ٵ���������\n",
        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		"����ʵЦ���еص��������棬���档��\n",
		"����ʵ̾�˿���˵���������ӿ���ô����ȥѽ����\n",
		"����ʵ���������滮���˼��£��ֳ�ü�����ط��¡�\n",
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","tigerstrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/food_item/soup6");
    
}

int hu(){
	if (REWARD_D->check_m_success(this_player(),"��������ʵ"))
		command("say Ӣ�ۣ�лл������Ұ���");
	else if (!this_player()->query_temp("marks/wanma/ʤ��Ʀ"))
		message_vision(CYN"����ʵ���ֵؿ�����һ�ۣ��Ż����ŵص���ͷ��\n"NOR,this_object());
	else
		command("say ���ѵ�˺���ϣ�̫���ˡ��������ǣ��ҵ�Ǯ�Ѿ������ӻ����ˡ���");
	return 1;
}
	

int accept_object(object who, object ob)
{
	if (ob->value()>=30000) {
		if (!who->query_temp("marks/wanma/ʤ��Ʀ")) {
				command("say �����Ҳû�á��������һ����Ҫ���ߡ�����");
				command("sigh");
				return 0;
		} else {
			command("touch "+who->get_id());
			command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
			if (!REWARD_D->check_m_success( who, "��������ʵ"))
			{
				REWARD_D->riddle_done( who, "��������ʵ",20, 1);
				who->set("marks/e_wanma/��������ʵ",1);
				tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
			}
			return 1;
		}	
	}
	command("shake");
	command("say ����Ĺ����ڰ���");
	return 0;
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"����ʵ����û�ջش��㡣\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/�ײ�֮��")) {
        	tell_object(me,"����ʵ˵��û��˵����������а���ý���\n");
        	return 1;
        }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó����������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n"NOR,this_object());
        another = new(__DIR__"panling");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}
