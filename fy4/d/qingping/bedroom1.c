//XXDER@fy3
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���䲻��Ҳû��ʲô���裬ֻ��ǽ�ϳ�������עĿ��ס���������Ī������
��η�����ﲻ�ǣ���������й��ﲻ�Ǵ����������Ǽ�������˫������������
���ѣ�����������䲻��ȴҲ�������˲��õľ���������
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
]));

   set("objects", ([
      __DIR__"npc/jin": 1,
   ]) );
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
