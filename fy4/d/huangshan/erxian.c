// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ഫ���������춼��ֻ�����㱳һ��·���˶���ʧ�㡣������־�̣���٩��λ
��ʿ��һ��һ�䣬�����˰�ɽ�µ�����Ժ�ĵ�·������Ϊ������ˣ��������ڴˡ�
���Ϊ��������һ�������ߣ������޳������Ҳ�һλ�ɷ���ǣ��ֳ����ƣ�����
�������׿�ɽ�����ǻ�٩��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jiyu",

]));
        set("objects", ([
        __DIR__"obj/huang" : 1,
	__DIR__"obj/zhang" : 1,
	__DIR__"npc/wangyulou" : 1,
                        ]) );
	set("coor/x",-55);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
