// zombie.c

#include <ansi.h>
#define MAX_TIME 200
inherit NPC;

void create()
{
        set_name("������", ({ "mask figure","figure" }) );
        set("long","�����ͷ�ϴ�������ͷ�֣��˳�׼����ʲ�ỵ�¡�\n");
		set("attitude", "heroism");
		set("hired_killer", 1);
		set_skill("dodge",1);
		set_skill("sword",1);
		set_skill("pyrobat-steps", 1);
		set_skill("lefthand-sword", 1);
        map_skill("move", "pyrobat-steps");
        map_skill("dodge", "pyrobat-steps");
        map_skill("sword", "lefthand-sword");

        setup();
		carry_object(__DIR__"obj/killerpai");
		carry_object(__DIR__"obj/killersword")->wield();
}

void heart_beat()
{
    object  hirer, targ;
    string  target;
	::heart_beat();
	
	if (!this_object())		return;
	if (!environment()) 	return;
			
	hirer = query("possessed");
    target = query("haunttar");
	
	if(objectp(targ = present(target, environment()))
		&& !this_object()->is_fighting() && living(targ) 
		&& !environment()->query("no_fight"))
	{
		if( targ == this_object()) return;
		if(userp(targ) && (int)targ->query("combat_exp") < 3000)
		{
			if( hirer)
				message_vision("$Nָ��$n˵�������־�����ɫ�����ң��ټ���\n",this_object(),targ);
			set_leader(0);
			call_out("destkiller",1);
			return ;
				
		}
		message_vision(HIR "$N��$n��ȵ������˻����������������������վ�����ļɳ����ϵ�ù�ɣ�\n"NOR,this_object(), targ);
		kill_ob(targ);
		set_leader(targ);
		targ->kill_ob(this_object());
    }
	else
		if( !this_object()->is_fighting() && hirer ) 
			this_object()->set_leader(hirer);
	
	if(this_object()->is_fighting())
		delete("idling");
	else
		add("idling",1);
	
	if(query("idling")>MAX_TIME) //200������400�룬���400��ȷʵû������������Ϊû����
	{
		set_leader(0);
		call_out("destkiller",1);
	}
}


int accept_fight(object me)
{
        return 0;
}

void destkiller()
{
	message_vision("$N�ٺ���Ц����������ү�����£����������ˣ���ת�����ʧ����Ӱ����\n",this_object());
	destruct(this_object());
	return ;
}


void unconcious() {
	die();
}
