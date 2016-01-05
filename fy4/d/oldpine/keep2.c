// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "կ��");
        set("long", @LONG
����Ӧ��������կ�ˣ���ȻΧ�������ǽ����ľͷ��ɵģ�������ϸһ������
�����Ҫ��λ�ö����˲���ɳ��ʯ�ѣ�������Ȼ��������ֵĺõط����������ó
Ȼ�Ӵ��ſڹ��������϶���Դ���ģ���կ������������ߣ�����Խ��һ��ľ׮֮
����Ǵ�����
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
        	__DIR__"npc/bandit_guard" : 2,
        ]) );

	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string exit)
{
        int i;
        object ob;

        if( exit != "east"
        ||      !query("exits/west") || !userp(me) )
                return 1;

        message("vision",
                HIY "�������������м���������У����Ź��ϣ����Ź��ϣ�һ��Ҳ�������������ߣ�\n"NOR
                        "�������䡹��һ����ͨ������Ĵ����Ѿ���һ���ʯ�����ˡ�\n",
                this_object() );
        delete("exits/west");

		REWARD_D->riddle_done(me,"������կ",10, 1);
        if (QUESTS_D->verify_quest(me,"̽����կ"))
			QUESTS_D->special_reward(me,"̽����կ");

        return 1;
}

void reset()
{
        object ob;

        ::reset();
        set("exits/west", __DIR__"keep15" );
        
}

void pipe_notify()
{
        object ob;

        message("vision",
                "������һ�����������̽ʶ�������ס�ſڵĴ�ʯ�����ر��ƿ��ˡ�\n",
                this_object() );
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
}
