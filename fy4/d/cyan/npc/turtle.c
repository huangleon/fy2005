
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("С�ڹ�", ({ "little turtle","turtle" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

		set("resistance/kee",100);

        set("long", "ɵ������һֻС�ڹꡣ\n");
	set("limbs", ({ "�ڹ��" }) );
	set("verbs", ({ "bite"  }) );

	set("chat_chance", 1);
	set("chat_msg", ({
                (: ccommand, "emote �����ڵ�������ȥ��" :),
                (: ccommand, "emote ���Դ��������" :),
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
	


		write("һֻССС�ڹ꣬���Ż��������Ŀǡ�
��СģС���ġ�
���������ų������죬�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ
��"HIG"�������ϲ���˿���˺ۡ�"NOR"\n");
		return 1;
	}
	return 0;
}