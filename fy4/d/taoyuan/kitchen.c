#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
        set("short", "����");
        set("long", @LONG
��������ߺܺã�����������һ�źܴ�İ��壬��������ʰ�÷ǳ��ɾ�������
����һ�������ߴ�ɵ���̨����̨�µ���˻����Ű���ɫ����̨�Ϸ���һ��������
��������Ʈ����Ũ���Ĵ���͵����Ĵ��̡�
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"cyard",
	]) );

	set("objects", ([
		__DIR__"obj/oven" : 1,
		__DIR__"obj/pot" : 1,
	]) );

	set("no_magic", 1);
	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
        }
        con = present("oven", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/scallion");
                item->move(con);
                item = new(__DIR__"obj/caidao");
                item->move(con);
                item = new(__DIR__"obj/lighter");
                item->move(con);
                item = new(__DIR__"obj/candle");
                item->move(con);
        }
}

int burn_notify(object ob) {
	object me;
	
	me = this_player();
	if(me->is_fighting()|| me->is_busy()) {
		return notify_fail("������æ��\n");
	}
	
	if (ob->query("id")!= "suishi") {
		tell_object(me,"������̨�Ͽ��˿�"+ ob->name()+"��\n");
		return 1;
	}
	
	message_vision(RED"$N����ʯ������̨�µĻ��Ϻ濾��\n"NOR, me);

	// Ҫ������һ����������Ҫ1/10* 1/10, Ҳ����˵��ÿ����10�Σ�10�������л�����100�����ӣ�(1M+ id only)
	if( REWARD_D->riddle_check(me, "��¶��ʯ")==6) {  
		destruct(ob);
		message_vision(HIY"\nʯƬ�������һ�����䣬¶��һ�龧Ө���εĻ�ʯ��\n"NOR, me);
		
		if (REWARD_D->check_m_success(me,"��¶��ʯ")) {
			message_vision(YEL"��ϸһ����ԭ���ǿ����ͣ������׷���˼�ˡ�\n"NOR, me);
			return 1;
		}
			
		
		if (!me->query("marks/ystone_gold"))
		{
			message_vision(HIY"\n��ϸһ����ԭ����һ������Ľ��ӣ�����\n"NOR, me);
			ob = new("/obj/money/gold");
			ob ->set_amount(100);
			if (!ob->move(me))
				ob->move(this_object());
				me->delete("riddle/��¶��ʯ");
				me->set("marks/ystone_gold",1);
		} else 
		{
			if(!REWARD_D->check_m_success(me,"��¶��ʯ"))
			{
		        REWARD_D->riddle_done(me,"��¶��ʯ",200,1);
			}      
			ob = new("/obj/specials/stone/ystone");
			ob->move(this_object());
		} 		
		
	} else {
		tell_object(me, "\nʯ�鱻���ù��̡�\n");
	}
	
	return 1;
}

