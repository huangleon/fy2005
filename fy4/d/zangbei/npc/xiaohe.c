#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("С��",({"xiao he","xiaohe"}));
	set("title",HIR"����� ɱ��"NOR);
   	set("long","
С��Ư���ü����Ѳ����Ǹ����ˡ����ϴ�˵С�����Ǵ���Ů�˵��·�����
ͷ������������������˶��ض��ᱻ����ȥ���ǡ�����������Ƥ������ֱ��
Ů�˻�ϸ���ף��ܶ��˶��������������������շ�ɳ�г�����ˣ���ô����
��ô�׵�Ƥ���������۾�ȴһֱ����ô��������ô������\n");

     	set("gender","����");
     	set("group","khlr");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",5500000);  
    	set("attitude", "aggressive");
    	
    	set("inquiry", ([
 		"*":	"�ϻ���˵����������",
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,1,"/obj/weapon/","fighter_w","lefthand-sword",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

void die(){
	 object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
		
		} 
        
        if (me)
        if (REWARD_D->riddle_check(me,"��԰����")==3)
        	REWARD_D->riddle_set(me,"��԰����",4);
/*        
        if(me->query("marks/kuaihuo/ҹ����Ӱ"))
        {
                me->set("marks/kuaihuo/��԰�̿�",1);
        }*/
        ::die();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",BLU"\n��Ӱһ������ʧ�ˡ�������\n" NOR, environment(),this_object() );
	environment()->set("xiaohe",1);
	destruct(this_object());
}