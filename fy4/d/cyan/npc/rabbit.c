
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ɽҰ��", ({ "rabbit" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

        set("long", "һֻ���úö��ĸ�ɽҰ�ã������Ŵ���䶢���㡣\n");
		set("limbs", ({ "��β��" }) );
		set("verbs", ({ "bite"  }) );

		set_temp("buffup/backfire","all");
		set_temp("buffup/backfire_amount",200);
		set_temp("buffup/backfire_msg",HIY"$N"HIY"���ϵ���ë��ɢ���裬�̵�$n"HIY"���������"NOR);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
					(: ccommand, "pain" :),
        }) );

		set("chat_chance", 1);
		set("chat_msg", ({
					(: ccommand, "lick" :),
					(: ccommand, ":).." :),
		}));
    set("intellgent",1);

	setup();
}
void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("һֻ���úö��ĸ�ɽҰ�ã������Ŵ���䶢���㡣
��СģС���ġ�
���������ų������죬�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ
��"HIG"�������ϲ���˿���˺ۡ�
"NOR+YEL"����С�����˺������٣�����ӱ������㣡"NOR"\n");
		return 1;
	}
	return 0;
}