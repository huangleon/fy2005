// Room: /d/oldpine/passage.c

inherit ROOM;

void create()
{
        set("short", "����ͨ�����");
        set("long", @LONG
��������վ��һ����ʯ��ͨ��֮�У������ϱ���һƬ����������Ļ������Ļ��
�洫�������¡¡��ˮ����ͨ�����ߵ�ʯ���ϰ��������ͭ������̨�����������
��Ѩ�������ƺ������⡣
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  		"��Ļ" : "��Ƭ��Ļ�ƺ�����һ�ּ�����˿��֯�ɵģ����滹��������ˮ����\n",
	]));
        set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"secrectpath1",
  		"south" : __DIR__"waterfall",
	]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/maniac" : 1,
	]));
        
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
