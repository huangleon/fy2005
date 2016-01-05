#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
�����Ǹ���������̸֮ɫ�������ԣ����˸ߵ�Ұ��������������ҡ�ڲ�����
��Χ��������ض��˺ü�ʮ����ͷ��������ȥ���ܾ�û���˼��룬Ĺ����һ�飬��
һ�鵹�ڵ��ϣ�һ���ưܲ����ľ���
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"southeast":__DIR__"tomb3",
	]) );
	set("objects", ([
                __DIR__"obj/daocaoren" : 1,
        ]) );
        set("item_desc", ([
		"paper": "һ��д�˼����ֵ�ֽ������ɫ�ܺڣ��������д��ʲô������ֻ��˺(tear)��������.\n"
	])); 
	set("in_action",0);
	set("coor/x",-60);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_tear","tear");
}

int do_tear(string arg)
{	
	object me,paper;
	int dodge;
	
	if (!arg ||(arg != "ֽ��" && arg != "paper")) 
		return notify_fail("��Ҫ˺ʲô������\n");
	me=this_player();
	dodge=me->query_skill("dodge",1);
	if (query("in_action")==1)
		return notify_fail("�����Ѿ���˺ֽ���ˡ�\n");
	if (query("in_action")==2) 
		return notify_fail("ֽ���Ѿ�����˺���ˡ�\n");
		
	message_vision(HIW"\n$N���ֽ�ֽ��˺��������������\n\n"NOR,me);
	set("in_action",1);
	message_vision(HIY"\n������ͻȻ����һ�£����еĿ�ɥ�����϶�����$Nֱ��������\n\n"NOR,me);
	if (dodge<20)
	{
		message_vision(HIR"\n$N���ͻ��������Ϯ����Ŀ�ɿڴ�����֪���룮������\n\n"NOR,me);
		message_vision(HIR"\n�����$N����ɥ�����һ̲���࣮������\n\n"NOR,me);
		me->die();
	}
	else
	{
		message_vision(HIR"\n$N���ͻ��������Ϯ�������Ų�æ�����Ծ���ߣ�������\n\n"NOR,me);
        	message_vision(HIR"\n��ɥ����$N��ǰֱ�Ӷ��£�������\n\n"NOR,me);
		paper=new(__DIR__"obj/paper");
		paper->move(me);
		me->start_busy(5);
		if (me && environment(me) == this_object())
		{
			call_out("shoot_me", 3, me);
		}
		else
			remove_call_out("shoot_me");
	}
	return 1;
}

void shoot_me(object me)
{
	int dodge;
	int kee;
	
	dodge=me->query_skill("dodge",1);
	kee=(int) me->query("max_kee")/3;
	message_vision(HIY"\nͻȻһƬ�ڹ�ӵ��������п�ɥ���İ�ͷ�ɳ���ֱ��$N��\n\n"NOR,me);
	if(dodge<60)
	{
		message_vision(HIR"\n$N���ܲ�������������ţ�������\n\n"NOR,me);
		me->receive_wound("kee", kee);
	}
	else
	{
		message_vision(HIW"\n$N���쳣����Ц���У��εض��𣬰���ȫ����գ�����\n\n"NOR,me);
	}
	message("vision",HIW"������ҡҡ�ڰ��ŵ�����ȥ��¶��һ��С·��\n"NOR,me );
	set ("in_action",2);
	if( !query("exits/east") ) 
 	{
		set("exits/east", __DIR__"tomb0");
		call_out("close_path", 20);
	}
	return;
}

void close_path()
{
        if( !query("exits/east") ) 
        	return;
        message("vision",
"һ��紵����������ҡҡ�ڰ��Żָ�ԭλ���ֵ�ס��ȥ·��\n",this_object() );
	delete("exits/east");
	set("in_action",0);
}

void reset()
{

::reset();
	if(query("in_action")) set("in_action",0);
        
} 
