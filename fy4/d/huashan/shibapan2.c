
inherit ROOM;

void create()
{
        set("short", "ʮ����");
        set("long", @LONG
�˴�ɽ�ƶ��ͣ���ɽ��·���ͼ�����·��ɽ�������̻���ʮ�а�����ɽ���ϣ�
·�Ծ����������㲻ʱ�ı�����ǣ���¹ڡ�
LONG
        );
    set("exits", ([ 
  		"east" : __DIR__"qingke",
  		"northeast" : __DIR__"shibapan1",
	]));
	set("objects", ([
		__DIR__"obj/jingji" : 1,
		__DIR__"npc/explorer2" : 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

