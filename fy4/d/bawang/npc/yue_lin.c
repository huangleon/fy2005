#include <ansi.h>

inherit NPC;
void create()
{

        set_name("����", ({"yue lin","yue","lin"}) );
        set("title", "����կ �󵱼�"NOR);
        set("nickname", HIB"���ϴ�"NOR);
        set("gender", "����");
        set("age", 43);
	set("long",
"���ϴ����Ĳ����ߴ󣬼�ȴ�������Ǳ�ģ���֫����������ֻҪ
һ���֣��Ϳ��Կ���һ��鼡�����·���������ͣ����������ȴ����
��ʲô���飬��ͭɫ��Ƥ����Ũüʨ�ǣ�ȴ����˫�����ۣ��۾��ﾫ
�����䣬������������������������ʱ��ض�׼�����������˶��ɵ�
��ɽ���ӡ�����˿��������뺷���ͣ����һ�һ����������������\n"
	);

        set("combat_exp", 200000+random(20)*10000);
        set("score", 170);
	set("attitude","friendly");

        set("bellicosity", 600);
              
        set_skill("force", 60);
        set_skill("blade", 100);
	set_skill("wind-blade",100);
	set_skill("parry", 80+random(50));
        set_skill("dodge", 70+random(50));
	
	map_skill("blade", "wind-blade");
	map_skill("parry","wind-blade");
        
        setup();

        carry_object(__DIR__"obj/heavy_blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        
}



void init()

{
	object me;
	::init();
	me = this_player();
	if(interactive (me) && environment(me) == environment() && !me->is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}



void greeting(object me)

{
	if((string)me->name() !="��ɽ��" && !me->query_temp("marks/keychain_ehg") ) 
	{
		command("say ��С���Ķ����ģ������̵ģ�����˭���ҿ���");
		this_object()->kill_ob(me);
	}
	else
	{
		command("say ��ɽ�����»ظ���Ҫ����ʲô��ˮ���̣���ҪѸ��ͨ��......\n���ˣ��ռ����˶��٣�");
	}
}

