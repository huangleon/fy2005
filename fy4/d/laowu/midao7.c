// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
ת�˼����䣬�붴�����ǰ���ֲ�����ָ����Χ��ʱ����С�����ӹ���ɳɳ
����������η�������ͷȴ�Ѳ�֪��ʱ�ĵ�·����������Ҳ�ֲ��嶫���ϱ���ֻ��
�����ŷ���׳�ŵ�����������ǰ�ߡ�
LONG
        );
   set("exits", ([ 
      "south" : __DIR__"midao3",
      "north" : __DIR__"midao9",
      "east" : __DIR__"midao8",
      "west" : __DIR__"midao5",
   ]));
	set("coor/x",100);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
