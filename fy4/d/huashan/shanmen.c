
inherit ROOM;

void create()
{
    set("short", "ɽ��");
    set("long", @LONG
ɽ���Խ�����ǰһ��ʯ��������ʯ������[33m����ɽ��[32m����������֣�ʯ�ź�ɽ����
��ͦ�Σ���ͷ�����͵��ָ������ƣ�һ����ʯС·����ɽʯ����������ȥ��С·��
������ڵ�ë�������������һƬ��䣬����������ˬ���ڿ��ȵ��������
·�������ܹ���һ��ô��һ���ط�Ъ�ţ�ʵ�ںܲ���
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"road4",
  		"south" : __DIR__"xiaojing",
	]));
	set("objects", ([
		__DIR__"npc/fatman" : 1,
		__DIR__"npc/xiaobao" : 1,
	]));
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",20);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}

