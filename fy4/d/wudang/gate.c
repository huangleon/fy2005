
inherit ROOM;

void create()
{
	set("short", "�䵱ɽ��");
	set("long", @LONG
һ��ΡΡ��ɽ�ţ�������д��[33m���䵱ɽ��[32m�����Ծ��Ĵ��֡��䵱ɽ����̫��ɽ��
�������㣬������Σ���Թžͱ���Ϊ�����µ�һ��ɽ�����ƴ��𣬼��������ʵ۶�
������ֲ�䵱���̣����������䵱ɽ�ԡ������������ĳ�ߵ�λ��Ϊȫ�����̵Ļ�
�����ġ�ԶԶ��ȥ������Ⱥ��ͦ����׿���ƺ���
LONG
	);
	set("exits", ([
		"north" : __DIR__"road1",
                "southup" : __DIR__"road2",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
