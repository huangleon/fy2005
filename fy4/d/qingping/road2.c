inherit ROOM;
void create()
{
        set("short", "��ʯС·");
        set("long", @LONG
����һ����ʯС·�����������˻��ܣ�����Щҩ�ģ��Ե÷ǳ����ľ�����ǰ��
��������ʯ·��С·һ�˵ľ�ͷ�ƺ���һ��СԲ�ţ�·�����Ǽ��䷿�ӣ�������ƽ
���ӵ��������ڣ��˴���ӷ�ס�ϱ����䡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"aroad",
  "north" : __DIR__"bedroom1",
  "south" : __DIR__"bedroom2",
   ]));

   	set("outdoors","qingping");
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
