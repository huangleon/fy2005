#include <ansi.h>
inherit SMART_NPC;

void event1(object me, int count);

void create()
{
        set_name("������", ({ "guo songyang", "guo"}) );
        set("title","��������");
        set("nickname",HIR"������"NOR);
        set("gender", "����" );
        set("age", 32);
        set("long", "
��������һ��ĺ��£��������Ѿ�����ĥ��ֻʣ�¼������ڵ�����������ͦ�Ÿ�
����ͷ­�����������ƺ�û������̧ͷ����һ�ۡ������Ǳ��������������ĵ���
�����������������������ˣ���ͷɢ�����²����壬���ĸ�������۵���������
��֫�ǽ���εĵ��ڵ��С�\n");
	set("combat_exp", 5000000);
        set_skill("sword", 100);
	set_skill("dodge", 40);
	set_temp("condition_type",RED "<������>" NOR);
	
	auto_npc_setup("liaoyin",200,200,0,"/obj/weapon/","fighter_w","huidashi",1);
	set_skill("perception",200);
	set_skill("sword",200);
	set_skill("sky-sword",140);
	map_skill("sword","sky-sword");
	map_skill("parry","sky-sword");
	set("NO_KILL","��ɱ���޻���֮��֮�ˣ�����Կ���\n");
	setup();
}



void	die(){
	object cloth;
	object me, owner;
        if (this_object()->query("can_die")) {
        	::die();
        	return;
        }
        if (this_object()->query_temp("in_talk"))
        	return;
        	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        set("NO_KILL","�������Ѿ�����һϢ�ˣ���������˵�����Ļ��ɡ�\n");
	if (!me) ::die();
	me->start_busy(10);
	event1(me, 0);
	set_temp("in_talk",1);
	
}

string *event1_msg=	({
	
	HIR"\n��������ڴ�ڵ�����Ѫ����������֧�أ���Ѫ˳�Ž���һ�ε��ʵ����ϡ�\n"NOR,
	
	HIC"���������е��������ʧ����֮���ֵ���һ���޷����ݵ���ɺͰ�����\n"NOR,
	
	HIC"�����������Ű���ͷ����ȻһЦ��л����л�㣬�������������������ǹ�������
���µ��ĵĹ������ˡ� \n"NOR,

	HIR"������ͻȻ�����и��������Ŵ���Ѫ�����С�����ó�һ��������Ѫ��ľ���� \n"NOR,

    	HIR"��������ȻһЦ���϶����������Ϲ١�����ôҲ�����뵽�����°ܽ�������������
���н�Ǯ����ն�񣬲����Ҳ��ܴ��ģ���ƣ���Ϊ������ҩ���޼�ľ���Ҵӳ����
��������á������١������١����� \n"NOR,
    
	HIC"\n�����������Ž�����Ѫ�۵��޼�ľ���������У���ȻһЦ����Ŀ���š�\n\n\n"NOR,

//    	HIC"\n�����������Ž�����Ѫ�۵��޼�ľ���������У���ǿ��˵�����˶������ѱ����ҽ���
//���������ڳ�������֮�£����ȡ����֮��˵����ȻһЦ����Ŀ���š�\n\n\n"NOR,
    	
});


void event1(object me, int count)
{
	object wood;
	mapping data;
	
	if ( !me || environment(me)!= environment(this_object())) 	return;
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		
		wood = new(__DIR__"obj/jq2-wood");
		
		if (wood) {
			wood->set("owner",me);
			wood ->move(me);
		}

		REWARD_D->riddle_set(me,"�ٴ���Ǯ",3);		

		me->stop_busy();
		set("can_die",1);
		delete_temp("in_talk");
		die();
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


void 	unconcious(){
	die();
}