#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�޻�", ({ "wuhua" }) );
        set("gender", "����");
        set("per", 40);
        set("class", "bonze");
        create_family("������", 17, "����");
        set("combat_exp", 3000000);
        set("long",
		"��ʵ�ڲ����������Ͼ�Ȼ������һ���ˣ�\n"
	);
        set("no_arrest",1);
                
        set_skill("blade", 150);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("wind-blade", 130);
        set_skill("ghosty-force", 150);
        set_skill("ghosty-steps", 180);
        set_skill("perception", 100);
        set_skill("lingxi-zhi",150);
        set_skill("unarmed",150);
        
        map_skill("unarmed","lingxi-zhi");
        map_skill("blade", "wind-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "wind-blade");
        map_skill("dodge", "ghosty-steps");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
        }) );
        
        
        setup();
	carry_object(__DIR__"obj/mblade")->wield();
	carry_object(__DIR__"obj/skinmask")->wear();
}

int do_test(object me)
{
	int	kee;
	if(objectp(me)) {
		if(environment(me) == environment()) {
			message_vision(HIY "\n$N˵������������أ���������һ����˵��\n"NOR, this_object());
			kee = (int)me->query("kee");
			COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
			if( (int)me->query("kee") < kee  || !present(me, environment())) { 
				message_vision(HIY "\n$N˵��������һ�ж��Ӳ��£�����������أ������Բ�������\n\n\n"NOR, this_object());
				return 1;
			}
			else {
				message_vision(HIY "\n$N��$n˵�����ã�����Թ�ȥ�ˡ�\n\n\n"NOR, this_object(), me);
				me->set_temp("marks/okey_to_see", 1);
				return 1;
			}
		}
	}
	return 1;
}
