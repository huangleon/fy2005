#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���Ϲ�", ({ "mai laoguang", "mai" }) );
        set("nickname","��Ѽ��");
        set("long",
"���Ϲ��Ǽ�����Ĵ�������û�����˼��������Ŀ�Ѽ������ˮ�ģ�
���Լ�ʹ���������ͣ��ͺ���������Ͷ���������Ҳû���ں���\n");
    	set("chat_chance",2);
		set("chat_msg",	({
			"���Ϲ�������ҵ��ص�����ϵ��������ϵ����úݣ���Ǯϵ���¶࣬Խ���Խϵ�á���\n",
			"���ϏV����Ц���s��������������ϵ�ͩo����ϵ���ȥ�ġ���\n", 

		})  );

        set("age", 50);
        set("combat_exp", 1000000);
        set("no_arrest",1);
        
		set_temp("apply/attack",50);
		set_temp("apply/damage",50);
		set_temp("apply/armor", 50);
		set_temp("apply/dodge", 50);
		set_temp("apply/parry",50);
		
		set_skill("unarmed",150);
		set_skill("dodge",150);
		set_skill("parry",150);
		set_skill("changquan",150);
		map_skill("unarmed", "changquan");
        
        set("vendor_goods", ([
				__DIR__"obj/kaoya":10,
                __DIR__"obj/sausage":15,
				__DIR__"obj/tongue":5,
        ]) );
		setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
       add_action("do_vendor_list", "list");
}

void die()
{
	object ob;
	object feng;
	object *enemy;
	feng = this_object();
	ob = query_temp("last_damage_from");
	
	if(ob)
	if(userp(ob)) {
		if(feng->query("name") == "������") {
			ob->set_temp("marks/fugui_killed_feng",1);
		}
		else {
			ob->set_temp("marks/fugui_killed_mai",1);
		}
	}
	::die();
}

void reset ()
{
	set("vendor_goods", ([
			__DIR__"obj/kaoya":10,
            __DIR__"obj/sausage":15,
			__DIR__"obj/tongue":5,
        ]) );
}

