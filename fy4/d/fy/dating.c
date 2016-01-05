inherit ROOM;
void create()
{
    set("short", "�����ķ�����");
    set("long", @LONG
һ�ۿ���ȥ������������ǽ�̻Իͣ��ûʸ���������̨���Ǵ����ģ�������
�ط�����ǧ���˰������ӣ�û�˻����ԩ��������������˴��СС�Ķ�����ֻҪ
��˵�����õĶľߣ����ﶼ�С����ң�����һ�顣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"pianting",
	"north" : __DIR__"yingou",
      ]));
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;31m		С�Ŀɰ��ң���Ŀɶ���[0m
[0;1;37m����������������������������������������������������������������[0m
             
���ӵĶķ���

�����������ࣾ����������

���ࣺ����������������������
������		��С	������������	һ��һ
����  		�Ĵ�	��������������	һ��һ
������		��Χ��	����������ͬ�㣩һ����ʮ��
��������	�ĵ���  		һ���

���ӣ�
��������������
����ʮ����С��
             
[0;1;37m����������������������������������������������������������������[0m             
TEXT
      ]) );

    set("objects", ([
	__DIR__"npc/dice_thrower" : 1,
	BOOKS"steal_30" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",-160);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

void init(){
    object me;
    me = this_player();
    if( me->query("gamble/amount")) {
		tell_object(me, "���ϴ���;��ţ���Ʒ̫���ˡ�\n");
		me->delete("gamble/amount");
		if (me->query_skill("betting",1))
		    me->decrease_skill("betting",1);
    }
}

void reset(){
    object obj;
    ::reset();
    if(!present("stealingbook", this_object())){
	obj = new(__DIR__"npc/obj/stealingbook");
	if(objectp(obj)){
	    if(!obj->move(this_object()))
		destruct(obj);
	}
    }
}
