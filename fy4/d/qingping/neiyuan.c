inherit ROOM;
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
һ���͵͵�Բ��С�ţ��ź���ǼҾ��ž�ס����Ժ�ˣ���Ϊ��ʦ��������ɴ��
��ʮ��ǰ��������������δ�飬���Ժ�Ժ֮����ʵֻס�����ǵĶ�������---����
��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"garden",
  "west" : __DIR__"road2",
   ]));

   set("objects", ([
      __DIR__"npc/hu": 1,
   ]) );
   	set("outdoors","qingping");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
