//Sinny@fengyun
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���ƹ�");
    set("long", @LONG
��������Ҷ�³�����ס�ĵط���Ҷ�³���ͼ��λ�Ѿá����԰��ƳǴ����Իʹ�Ϊ
ͼ��������Ψ�д˴���Ϊ���š�СС�ĵ����ڣ�һ����һ�Σ�һ���Ŷ��ѡ�ǽ���м�
Ϊ����ǰ�������������ɵ�Ф���ɷ���ǣ��뷢ƮƮ������Ϊһ�����������飺
                     
                      һ��������������ɣ�
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"changlang3",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/master" : 1,

      ]));
    set("item_desc", ([
	"hassock": "һ����Щ��ͷ�����ţ����ż���С�֣�ߵ�ף�kneel��ǧ�Σ���ʯΪ����\n",
	"����": "һ����Щ��ͷ�����ţ����ż���С�֣�ߵ�ף�kneel��ǧ�Σ���ʯΪ������\n"
      ]) );


    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-280);
    set("coor/z",30);
    setup();
}
void init()
{
    add_action("do_kneel","kneel");
}       


int do_kneel(string arg)
{
    object me,book;
    int i, max_sen, max_kee,max_gin;
    me = this_player();
    max_kee = me->query("max_kee");
    max_sen = me->query("max_sen");
    max_gin = me->query("max_gin");
    if(me->is_busy()) 
	return notify_fail("��Ķ�����û����ɣ�����ߵ�ס�\n");
    if (me->query("sen") <= max_sen /10 || me->query("gin") <= max_gin /10|| me->query("kee")<=max_kee/10)
    {
	return notify_fail("���Ѿ���ƣ�����ˣ��޷��ٿ�ͷ�ˡ�\n");
    }

    message_vision(HIC"$N���������ϣ�����ʯ�ڵİ����ɵ�Ф��һ��һ�µĿ���ͷ����������\n"NOR,me);
    me->add("gin",-(max_gin/50));
    me->add("sen",-(max_sen/50));
    me->add("kee",-(max_kee/50));
    if(random(200)||(int)me->query_temp("by_kneel")>=1)   
	tell_object(this_object(),"��������ᱳʹ��ͷ��������Ӳ����֫��ʼ���飬�����������죬�ƺ���ʱ��һͷ�ص�����\n");
    else {
	message_vision(HIY"�����������һ�����ӣ�һ�������ڵ��ϣ����æʰ��$N���У�\n"NOR, me);
	book = new(BOOKS"skill/calligraphy_60");
	book->move(me);
	me->add_temp("by_kneel",1);
    }
    me->start_busy(3);
    return 1;
}

