inherit ROOM;
void create()
{
        set("short", "ɽׯ����");
        set("long", @LONG
���������ƽɽׯ�Ĵ��ţ���ɫ�Ĵ��ſ���ȥ����ͨͨ��ֻ���Ŷ��ϵġ���ƽ
ɽׯ��������������עĿ���ſ����ż�λ��װ���꣬������ƽ���µ��ӣ�һ���ϻ�
����֦Ҷï�ܣ��ƺ�������ׯ���Ķ��ط�ǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang1",
  "west" : AREA_JINAN"road",
]));
   set("objects", ([
      __DIR__"npc/lu": 1,
      __DIR__"npc/young": 2,
   ]) );

   	set("outdoors","qingping");
	set("coor/x",-70);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
