// CYNGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(HIW"����"NOR"Ů��", ({ "white girl","girl" }) );
        set("long", "�����ʵ������У���ֻ��ģģ�����Ŀ���������Ӱ������֪Ϊ�Σ������һ���ӱ�
���ޱȵ���������͡�\n");
	set("age",18);
        set("per",50);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 500000);  
	set("kee", 1500);
        set("max_kee", 1500);
        set_skill("meihua-shou",80);
        set_skill("unarmed",80);
        set_skill("force",50);
        set_skill("qidaoforce",50);
        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("fall-steps",80);
        set_skill("iron-cloth",100);
        set_skill("spring-water",200);
        set("force_factor",10);
        set("max_force",100);
        set("force",200);
        map_skill("force","qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("unarmed","meihua-shou");                         
        map_skill("iron-cloth","spring-water");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"iron-cloth.bingwantianzhang"  :),

        }) );
        
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}

void init()
{
	::init();
	add_action("do_look","look");
}

void leave_room(object me)
{
	object pipe;
	
	tell_object(me,WHT"������ת��������翣������㻳���Լ��ǲ����ۻ���ʱ���㿴����ɳ̲����һ��
���£��ѵ�������λŮ�����µģ����������ɵ�ʰ�����Ǹ����£�������һֻ���ӡ�\n"NOR);
	pipe=new(__DIR__"obj/saintpipe");
	pipe->move(me);
	pipe->set("receiver",me);
	destruct(this_object());
	return ;
}

int do_look(string arg)
{
	object ob,me;
	
	if(!arg) return 0;
	me=this_player();
	ob=present(arg,environment());
	if(!ob) return 0;
	if(ob==this_object()&&(!me->query_temp("lovestory1_epilogue"))) 
	{		
		tell_object(me,"�ۻ�������ôʲô����������\n");
		return 1;
	}
	return 0;
}