#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

void create()
{
        set_name("���ϵ�", ({ "du laodie" }) );
        set("gender", "����" );
        set("age", 60);
        set("long","
���ϵ���˵��Ѫ�ֶ�ɱ�����壬������������Ȥ�Ļ����������İ�
�����ഫ�ϵ�����ʱ�����ź�������������๤�����˵��Ǻպ�������\n");

		set("combat_exp", 800000);
        
        set("inquiry", ([
        	"����޼":	"����޼���������裱����������֮����������ʹ�þ��ϡ�\n",
        	"������":	"������������Ѫ���裵��������֮����������ʹ�þ��ϡ�\n",
        	"��������": "������������̱���裱����������֮����������ʹ�þ��ϡ�\n",
        	"����֮��":	"���������м䣬�������ⰵ���ķ���֮����\n",
        ]));
        
       	set("chat_chance", 1);
        set("chat_msg", ({
        	"���ϵ�һ��һ��˵���������ҵİ������ͱ���ѧ��"YEL"����֮��"NOR"��\n",	
        }) );
        
        set_skill("unarmed",100);
        set_skill("changquan",200);
        set_skill("puti-steps",150);
        set_skill("dodge",100);
        set_skill("move",100);
        map_skill("unarmed","changquan");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
                
        set("attitude", "friendly");
        set("vendor_goods", ([
               __DIR__"obj/zhen": 10,
               __DIR__"obj/lei": 10,
               __DIR__"obj/jili": 10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth",([	"name": "������",
    						"long": "һ���ͼ��߰ߵĹ�������\n",
    						 ]))->wear();    
}

void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}


void reset(){
	        set("vendor_goods", ([
               __DIR__"obj/zhen": 10,
               __DIR__"obj/lei": 10,
               __DIR__"obj/jili": 10,
        ]) );
}