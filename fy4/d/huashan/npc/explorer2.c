// explorer.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
        object weapon,armor;
        
        set_name("��ɽ������", ({"mountain climber","climber"}) );
        set("gender", "����" );
        set("age", 36);

        set("class","beggar");
         set("long",
		"���ԹŻ�ɽһ��·����������ʮ�������ʵǵģ���Ȼ�Ǿ���
ǿ׳�����ģ���໹���书��\n"
		);
        set("combat_exp", 2200000);
        
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"��ɽ��Ц�������⻪ɽ֮�գ�Ҳ�����������ѣ���\n",
	 	"��ɽ��ָ���ͱ��ϵ�ӥ��˵�������ϻ��ۣ��Ϳ���������ȥ��Сӥ׽��������\n",
	}) );
        
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(40) :),
	     }) ); 		

		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","dagou-stick",1);	
	    setup();
	    carry_object(__DIR__"obj/shoe")->wear();
	
	    armor=new("/obj/armor/cloth");
	    armor->set_name(WHT"��ɽ��"NOR,({"cloth"}) );
	    armor->move(this_object());
	    armor->wear(); 
	
	    weapon=new("/obj/weapon/staff");
	    weapon->set_name(WHT"��ɽ��"NOR,({"staff"}) );
	    weapon->set("value",0);
	    weapon->move(this_object());
	    weapon->wield(); 
	    carry_object(__DIR__"obj/leathersleeves.c")->wear();
}
