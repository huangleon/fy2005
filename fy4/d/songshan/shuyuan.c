// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������Ժ");
        set("long", @LONG
��̫��ɽ��´�ġ�ɽˮ����֮�����޵ز�Ⱦ�󳾡�֮���������̺�һ�Ľ�����
ӳ��ï����������̴��У��������ҹ��Ĵ���Ժ֮������Ժ�����������Ƿ��£���
Ϊ���ۣ�������Ϊ��Ժ���δ���ѧ�ҳ����ֵ����ڴ˽���ѧ��Ժ�ڵĽ����أ���
�������ۼ�ʥ�¸�Ӧ֮�̱��������������Ĺ屦��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shaoshi", 
  "east" : __DIR__"chongfu",
  "southeast" : __DIR__"zhongyue",
  "northeast" : __DIR__"shita",
]));
        set("objects", ([
                __DIR__"npc/teacher" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
