// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
void create() {
    	set_name("��С�ĺ�Ӱ", ({ "shadow"}));
    	set("long", "������һƬ��ڣ��㿴��������˵���ò��\n"
        );
    	set("gender", "Ů��");
    	set("class","huashan");
    	set("age", 59);

		set("no_arrest",1);
		set("no_fly",1);

		set("chat_chance", 1);
        set("chat_msg", ({
                "��Ӱת��һȦ���ƺ��ޱȽ�����\n",
                "��Ӱ����������Ѿͷ�ֵ�����ȥ�ˣ�\n",
                }) );
   
    	set("combat_exp", 4000000);
    	set("attitude", "friendly");
    	set_skill("unarmed", 200);
    	set_skill("zhaixin-claw",200);
    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("parry", 200);
		map_skill("unarmed", "zhaixin-claw");
    	setup();
    	carry_object("/obj/armor/cloth", 
               ([      "name"  :       HIB "������"NOR,
                        "long"  :       0 ])
        )->wear();
}



int kill_ob(object who)
{
	object me;
	::kill_ob(who);
	delete("timer");
	if (!is_busy())
	{
		ccommand("qusi "+who->query("id"));
		ccommand("perform zhaixin");
		if (who->query("kee") < 0)
			ccommand("die2 "+who->query("id"));
		else
			ccommand("fake");
	}

	return 1;
}


