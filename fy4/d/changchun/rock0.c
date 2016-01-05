// searoad.c
#include <ansi.h>
#define MINAGE 20
#define MAXAGE 80
#define FATEMARK "����B/����_����"

inherit ROOM;
void create()
{
	set("short", "��ʯ");
	set("long", @LONG
����ɽ�ң����漱�����ȣ�������ӿ��������ǧ�ٿ���ް�Ľ�ʯ������ɽ��
���ǹ�ʯ�϶룬����ն񡣽�ʯ�������ӿ���ȣ�ѩ�׵��˻����ɼ��Ľ���
LONG
	);
	set("exits", ([
		"north" : __DIR__"island",
		"east" : __DIR__"rock1",
	]));
	set("outdoors", "tieflag");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init_scenery()
{
	remove_call_out("event_tide");
	call_out("event_tide",1,0);
}



string* msg= ({
	HIY"����֮���� ��ʯ����� ����΢���� �����İ���
��ĿԶ���� �����������գ���ϼ���졣 \n\n"NOR,
	HIY"Ϧ��ȽȽ�뺣�����������ں����ϡ���������𲨣���ҫ���ѣ������ޱȡ� \n\n"NOR,
	WHT"ɳ���ϣ�Ÿ�ط�����ɳ���Ӱ������ƹ���Զ��
ż������������ƮƮ���ã�Զ�����⡣ \n\n"NOR,
	RED"ˮ�콻��֮����ĺ��������Ⱦ��ǧ���̲���硣 \n\n"NOR,
	HIW"�̺�����֮�У���������һҶ�������׷�һ�ơ���������Ƕ�ں���֮�ϣ�
ˮ��֮�䡣 \n\n"NOR,
	HIR"���ս���������Զ����䣬�������ϡ��������죬
��Զ��������ʱ�����������ף����춯�ء� \n\n"NOR,
	HIM"��Ŀ��ȥ�����ϲ���ɽ����������ӿ��һ�������򺣰����۶����� ����
���ס�˲�伴�����Ļ�������������ʯ���ƣ������Ѱ����������ذ�ɫ��
ˮ�����ѩ���ں��������������ӡ� \n\n"NOR,
});


void add_fate_mark(object ob)
{
	int num = 1+random(10);
	if(!random(0)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void event_tide(int count)
{
	object *ppls,ob;
	function f=(:add_fate_mark:);
	ob=this_object();
	if(count==sizeof(msg))
	{
		ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query("age")>=MINAGE && $1->query("age")<=MAXAGE && !$1->query(FATEMARK):));
		if(sizeof(ppls))
			map_array(ppls,f);
		return ;
	}
	message("vision",msg[count],ob);
	call_out("event_tide",5,++count);
	return ;
}

