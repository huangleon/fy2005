// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
        set("short", "ˮ̶");
        set("long", @LONG
��������վ��һ������׵�ˮ̶���ϣ���̶�ײ�ʱ������ð������ɢ����һ
�ɹ������ζ��ˮ̶�߳�����[37m��ɫҶ��[32m�Ĺֲݣ����ܶ��͵�ɽ�ڽ���ֱ����̧ͷֻ
��һ����Բ�ε���գ�Ψһ�ĳ�·���ֻ������ɽȪ����ˮ̶��ȱ�ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  			"north" : __DIR__"riverbank1",
		]));
		
        set("item_desc", ([
        	"��ɫҶ��": 	"ˮ̶�߳����˻�ɫ��Ҷ�ӣ�������Ҷ̶��\n",
        ]));
               
        set("objects", ([ /* sizeof() == 1 */
  			__DIR__"npc/serpent" : 1,
		]));
        set("resource/water", 1);
        set("liquid/name", "��Ҷ̶ˮ");
		set("coor/x",0);
		set("coor/y",-10);
		set("coor/z",0);
		setup();
        replace_program(ROOM);
}
