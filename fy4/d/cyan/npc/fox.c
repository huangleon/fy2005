
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("С����", ({ "little fox","fox" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

		set_temp("buffup/evade_amount",999999);

        set("long", "ɵ������һֻС���ꡣ\n");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 1);
	set("chat_msg", ({
                (: ccommand, "emote ̧ͷ�����㣬ɨ��ɨβ������һ�ߡ�" :),
                (: ccommand, "emote ����ͷ����СϪ���к���һ��ˮ��" :),
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
	


		write("ɵ������һֻС���ꡣ
��СģС���ġ�
���������ų������죬�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ
��"HIG"�������ϲ���˿���˺ۡ�"NOR"\n");
		return 1;
	}
	return 0;
}