#include <ansi.h>
inherit SMART_NPC;
int escape();

void create()
{
        set_name("����", ({ "bird","chicken","crossoptilon" }) );
        set("race", "����");
        set("age", 10);
        set("long", "
һֻ��ɫ�Ĳ�����ͷ�������ɫ��ͷ�����������ܵĺ�ɫ�̵���״��
ë������ʴ�״����ɫ���������̽���������š������ڵ��ϱı�����
��Ѱ��ʳ�\n");
        
	set_skill("move",2000);
	set("chaser",1);
	set("combat_exp", 300000);
    	
    	set("max_kee",1200);
    	set("max_sen",600);
    	set("max_gin",600);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(: escape() :),
        ]) ); 
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		CYN"��������������������ؽ���������\n"NOR,
		"���������ų������������䵽�յص���һ�ߡ�\n",
    	}) );  	
        setup();
}


int escape(){
	object ob,*env,room;
	int i;
	
	if (environment(this_object())->query("in_tree")) return 1;
	
	message_vision(CYN"\n"+name()+"�������ؾ����ţ��Ĵ��ų��������ԱߵĴ�����������������æ���ˡ�\n"NOR,this_object());
	env=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(env);i++)
		if(userp(env[i])) env[i]->set_temp("marks/zangbei/������",1);
	room=find_object(AREA_ZANGBEI"pine2");
	if (!objectp(room)) room=load_object(AREA_ZANGBEI"pine2");
	this_object()->move(room);
	return 1;	
}	
