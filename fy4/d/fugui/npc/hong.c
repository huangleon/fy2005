#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "hong niangzi", "hong" }) );
        set("gender", "Ů��" );
        set("long",
         "�����Ϻ���Ҳ�ڷ��⣬һ�ֺ��ҫ�ۣ�������������Ĺ⡣��������\n�ϵ�Ȼ���ź��·������ⲻ�Ǵ����·��Ϸ������ģ���ʵ�ϳ����·�\n�⣬������ÿ���ط������ڷ��⣬�����������۾�������Ц��\n");
        set("nickname", HIR "�ȿ����"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
        "�������۲��������������˸����ۣ���Ц��Ц�������ҳ�����������\n�������İ�����\n",
                                })  );

       	set("combat_exp", 1000000);
        set("no_arrest",1);
        
        set_skill("unarmed", 150);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 120);
        set_skill("move",120);
        set_skill("cloudforce",60);
        set_skill("chaos-steps",150);
        set_skill("tigerstrike",150);
        
        map_skill("unarmed","tigerstrike");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps");
        map_skill("force","cloudforce");
        
        setup();
	carry_object(__DIR__"obj/redcloth")->wear();
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	message_vision(HIW"$N�۲����������$nһ�ۣ���Ц��Ц����������֪�����������ģ�\n��ô�������Լ�������������ҩ���ڷ�ͷ���Լ�ȥ�ðɡ���\n"NOR,this_object(),ob);
		
}
