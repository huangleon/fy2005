
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ն��̨��");
        set("long", @LONG
�˴�����ն��̨�����汱�������̺����죬�����뵣�һҶ�����������ϼ�����
���������ʧ������ת����ΡȻ������Զ������¥������ԼԼ���в���̨ͤ¥��
̨��������һ�����������������������ͬ���һ�㣬���˷�бб��������������ң
ָ���ס�
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"zhanmangtai",
	    ]));
		set("no_fly",1);
	set("objects", 
	   ([ 
			__DIR__"npc/sen":1,
	    ]));
/*       set("item_desc", ([
                "����": "һ��Ӥ������һ���ϸ�ľ�����������ۣ���ϸ�鿴�����ŷ���
����һ�����񣬶������ƺ����԰ᶯ����move��\n",
                 "serpent": "һ��Ӥ������һ���ϸ�ľ�����������ۣ���ϸ�鿴�����ŷ���
����һ�����񣬶������ƺ����԰ᶯ����move��\n"
        ])); 
*/
        set("outdoors", "baiyun");

	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();
}

void init()
{

//        add_action("do_move","move");
}

int do_move(string arg)
{       
        object me;
        int dodge;
       
        if (!arg ||(arg != "����" && arg != "����"&& arg != "serpent")) 
                return notify_fail("��Ҫ��ʲô������\n");
        me=this_player();
        dodge=me->query_skill("dodge",1);
        if (query("in_action")==1) 
                return notify_fail("����֮���Ѿ����ƶ����ˡ�\n");
                
        message_vision(HIC"\n$N�����Ͼ��������ƶ�����֮�ף�������\n\n"NOR,me);
        message_vision(HIR"\nɲ��֮�䣬�����ƶ��ľ���֮��ͻȻ�Ŵ�Ѫ��޿ڣ�������ͬ����һ���
������$N�������������\n\n"NOR,me);
        if (dodge<80)
        {
                message_vision(HIC"\n$N����һ����ʹ�������������ת��Ų�������ڲ�������֮�٣�\n\n"NOR,me);
                message_vision(HIR"\n$N�����ؿ�Ѫ��һ�����������ѹ��ض�����������\n
$N����ͷ���޷����ŵĿ����ؿ�����Ѫ�ս���ɢ�����˵ض�����\n"NOR,me);
                me->die();
        }
        else
        {
                message_vision(HIC"\n$N��ȻһЦ�����μ������磬���������������\n\n"NOR,me);
                message_vision(HIW"\n��������$N�ؿڼ��������������\n\n"NOR,me);
                me->start_busy(5);
                if (me && environment(me) == this_object())
                {
                        call_out("shoot_me", 3, me);
                }
                else
                        remove_call_out("shoot_me");
        }
        return 1;
}

void shoot_me(object me)
{
	object box,cloth,seal,hat;
        int dodge;
        int kee;
        dodge=me->query_skill("dodge",1);
        kee=(int) me->query("max_kee")/2;
        message_vision(HIC"\n$N����δ����ͻȻ��̨�˷���������է�𡣡�\n\n\n"NOR,me);
        if(dodge<100)
        {
                message_vision(HIR"\n������ߵİ˱�����ǿŬһ�㼲�������$N�ҽ�һ�����˰ѳ���͸����롣\n\n"NOR,me);
                message_vision(HIR"\n$N����Ѫ����ע����ɫ��ͬ��ֽһ�㣬һ�����ģ����ڵ��ϡ�\n\n"NOR,me);
                me->receive_wound("kee", kee);
                me->unconcious();

        }
        else
        {
        message_vision(HIW"\n$N�������������𣬷·����Ӱ��������ɶ��������\n\n"NOR,me);
        message_vision(HIC"$NƮȻ���£������˰ѳ�������������֮��أ�����˲�����\n"NOR,me );
        message_vision(HIY"\n\n$N��Ŀ��������ȥ�����Ƶ������Ѿ��ɿ���¶��һ��������ӡ�\n"NOR,me);
        message_vision(HIW"\n\n$N��ɫһ�ݣ�С�ĵذ�����������뻳�С�\n"NOR,me);
        box=new(__DIR__"obj/goldbox");
        cloth=new(__DIR__"obj/emperor_cloth");
        seal=new(__DIR__"obj/jade_seal");
        hat=new(__DIR__"obj/sinny_hat");
        cloth->move(box);
        seal->move(box);
        hat->move(box);
        box->move(me);
        set ("in_action",1);}
}


void reset()
{

::reset();
        if(query("in_action")) set("in_action",0);
        
} 



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
