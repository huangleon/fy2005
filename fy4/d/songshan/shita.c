// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����ɽ��´��������ɼ�������������������ϵķ������׳Ʊ�κ����������
�����ϴ�Ƭƽ̹�����أ��ӵ����洦�ɼ�ש������ˮ������ש��������͹��ŵĻ�
��ש���ߵ�������ƽ��������ʮ�����Σ���������Ϊ�������Ρ�ȫ���ɻ�̨������
���ܣ���ɲ�����ں���ӡ�������֮�棬�Ѷ�֮���Ǿ��޽��еġ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"fawang", 
  "east" : __DIR__"huishan",
  "southwest" : __DIR__"shuyuan",
]));
        set("objects", ([
                __DIR__"npc/amao" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
