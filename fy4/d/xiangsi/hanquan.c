// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ϻ�Ȫ");
        set("long", @LONG
����һ����Ⱦ����̲�̦��ˮ��������ˮ�����ɣ���Լ͸�����ƺ�����
��Ե�ϵ���ꤿ������Ѿ������ˣ��ϵ���������ĥ���Ѿ������ӡ��������
��ȴ��Ȼ�������Լ���ְ�𣬽�ɽ���е���Ȫ�����������칬����˵�⾮��
����Ů��ȡˮ֮�������˾��е�ˮ�����������ա�û����֪����˵�����Ǽ�
��ֻ���������������֮Ϊ�����������ꡣ(���� ����)
LONG
        );
	set("objects", ([
		__DIR__"npc/girl" : 2,
	]));
	set("exits",([
  		"west" : __DIR__"nanzoulang",
  		"east" : __DIR__"gelou",
  		"north" : __DIR__"zoulang",
	]) );

	set("outdoors", "xiangsi");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("do_fill", "fill");
	add_action("do_dip","dip");

}


int do_dip(string arg){
	
	object weapon, me;
	
	me = this_player();
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
	weapon = me->query_temp("weapon");
	
	if (objectp(weapon))
	{
		if (weapon->query("owner")) {
			message_vision(WHT"$N��"+ weapon->name()+NOR WHT"����Ȫ�У�ֻ��һ�ɺ�����������������ס��
			
"+weapon->name()+NOR WHT"�������԰㼤����ˮ��

����һ�Ϲ�â���ɵİ������𣬵�����������ˮ���������ڣ��ɻ�$N���С�	\n"NOR,me);
			weapon->set("ice_blade",1);
			weapon->save();
		} else
			message_vision(WHT"$N�������Ӱ�"+weapon->name()+NOR WHT"���뾮ˮ֮�У�͸�ĵĺ��Ⱑ��\n"NOR,me);
	} else
		tell_object(me,WHT"��������Ӱ��ֽ��뾮ˮ֮�У�͸�ĵĺ��Ⱑ��\n"NOR);
	
	me->perform_busy(1);	
	return 1;
}

int do_fill(string arg)
{
    string name, type, container;
	object me,skin,dew;
    int drunk_apply;
    function f;
    
	me = this_player();
	if (!arg)
		return 0;
	skin = present(arg,me);
	if (!skin)	return 0;
    if( me->is_busy() )
	{
		write("����һ��������û����ɡ�\n");
		return 1;
	}

	if (!skin->query("liquid/name"))
	{
		write("��û��װˮ�Ķ�������\n");
		return 1;
	}

    if( skin->query("liquid/remaining") )
        message_vision("$N��" + skin->name() + "��ʣ�µ�" + 
                       skin->query("liquid/name") + "������\n", this_player());

    type="water";
    name="���Ϻ�Ȫ";
    container="��";
    drunk_apply = 6;

    message_vision("$N��"+container+"�н�" + skin->name() + "װ��"+name+"��\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));

	f = (: call_other, __FILE__, "drink_drug" :);    
    
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
 	skin ->set("liquid/drink_func", bind(f, skin));  
    return 1;
}


int drink_drug(object ob)
{
    object me = this_player();
    int amount;
    
    if (me->query("class") == "moon") {
		tell_object(me,HIG"�߹ǵı��������������ֻ����������������̥���ǣ������泩��\n"NOR); 	
		amount = me->query_skill("snowforce",1)* (100 + me->query_skill("prescription",1)/4)/100;
		amount = COMBAT_D->magic_modifier(me, me, "kee", amount);		
		me->receive_curing("kee",amount);
		me->add("water",-1);
	}
    return 0;
}

