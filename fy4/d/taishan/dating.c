// Room: dating.c --- by MapMaker

inherit ROOM;
#include <ansi.h>
string jinbian_desc();
void create()
{
	set("short", "������˫��");

	set("long", @LONG
�������������˫�������а��輫Ϊ�򵥣���ȴ��ɨ��һ����Ⱦ��������͸��
��������أ����ж˶�����������̴ľ���������Ϸ���յ�͵ƣ��Աߵ�̫ʦ���϶�
�����޹�ɽׯ������������赣���΢��˫�ۣ������ḧ�����н𽣣�����¶���ּ�
ڽ��м��Ц�ݡ��������Ϸ����߸߹��Ÿ����ң����š�������˫���ĸ�պ����֡�
LONG);

	set("exits",([
	"east":__DIR__"shufang",
	"west":__DIR__"woshi",
        "out":__DIR__"damen",
	]) );
        set("objects", ([
                __DIR__"npc/lian" : 1,
        ]) );
	set("item_desc", ([
		"����" : (: jinbian_desc :),
        "jinbian" : (: jinbian_desc: ),
	]));
	set("indoors", "taishan");
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",150);
	set("mengce",1);
	setup();
}

string jinbian_desc()
{
	if (query("mengce"))
	{
		return "һ��޴�Ľ��ң��������������˫�ĸ����֣����ƺ����Һ��������ŵ�ʲô������
��֪���ɷ�����leap������ȡ�������� \n";
	}else
		return "һ��޴�Ľ��ң��������������˫�ĸ�����\n";
}

void reset()
{
	this_object()->set("mengce",1);
	::reset();
}

void init(){
	add_action("do_leap", "leap");
}

int do_leap(string arg){
	object lian, me;
    object mengce;
	me = this_player();
	if(!arg || (arg != "up" && arg != "����" && arg != "jinbian"))
		return notify_fail("��Ҫ����������\n");
     if (me->query_skill("dodge",1) < 100)
        return notify_fail("����̫�ߣ��������ڵ��Ṧ���Ǹ����������ġ�\n");
	 message_vision(HIC"\n$N���˿�����ͻȻ����һԾ��\n"NOR,me);
	if (random(me->query_skill("perception",1))>50)
	{
		if (this_object()->query("mengce"))
		{
			message_vision(
					HIC"һ�����ӷ���$N�ӽ��Һ�Ѹ�ײ����ڶ�ȡ��һ����ᣬ���ɵ����ڴ����С�\n\n"NOR, me);
			mengce=new(__DIR__"obj/mengce");
			mengce->move(me);
			this_object()->delete("mengce");
		}else
			message_vision(RED"$N�������Һ�տ���Ҳ���ƺ�ʲôҲû�С�\n"NOR,me);

	}else
	{
		message_vision(HIW"˲Ϣ֮�䣬$N�޷�������Һ���Щʲô��\n"NOR,me);
	}
	me->start_busy(3);
	if( lian = present("lian", this_object()) )
	 {
                message_vision(
"\n$N"HIR"���һ��������$n�ٺ�Ц�����δ���ͽ���������޹�ɽׯ��Ұ��\n
$N"HIR"�������͵�˲��ߣ�ɱ���⣡\n\n"NOR,lian,me);
                lian->kill_ob(me);
       
       }
		return 1;
}

