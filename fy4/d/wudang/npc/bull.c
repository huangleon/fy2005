inherit NPC;

string desc();

void create()
{
	set_name("��ˮţ", ({ "bull" }) );
	set("race", "����");
	set("age", 3);
	set("long", (: desc :));

	set("chat_chance", 1);
	set("chat_msg", ({
		"��~~~~~��~~~~~\n",
		"��ˮţû�߼�������ͨһ�¹��ڵ��ϣ������ǲ����ˡ�\n",
		"��ˮţ����ؿ����㣬�ƺ�������������\n",
		
	}));
	set("combat_exp",20000);
	
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 100);	
	setup();
}


string desc(){
	string msg;
	
	if ( random(2))
		return "һ����ţ���޾���ɵ�վ�š�\n";
	else
		return "һ����ţ���޾���ɵ�վ�ţ������и�ŧ�����ƺ��Ǳ�ʲô����ҧ�ģ�
�ǲ��Ǹ���������ʲô���������ң�\n";
}