
inherit ROOM;

void create()
{
    set("short", "������վ");
    set("long", @LONG
ÿ�������ƥ��������������������Ρ����۹�Ա���ۻ�����ͨ���ն�������
�������ʼ����š������������Ҫ�ĵ����ֻҪ������վ������֮�ھ��Կ���
�͵���������͢������֧������Ҳ����������(Sign)���͹���������ϻ������
����������������⡣
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"fengdoor",
      ]));
    set("objects", ([
	__DIR__"npc/officer": 1
      ]) );
    set("item_desc", ([
	"sign": @TEXT
[37m��վ�������ݣ�
������������(rent mache): ����8��
�������ռ��ż��������������������ѯ�ʡ��š�����ѯ���䡣
[32m
TEXT
      ]) );

    set("coor/x",-40);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

int valid_leave(object me, string dir)
{
    object mbox;

    if( mbox = me->query_temp("mbox_ob") ) {
	tell_object(me, "�㽫���佻����վ��\n");
	destruct(mbox);
    }
    return 1;
}
