// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "fengqing" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹����·��ֱ���ʦ");
        set("long", "�����˹����������������ķ��ֱ���ʦ��\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");

	set("age", random(40)+20);
        set("cor", 24);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���忴�˿��Լ��Ķ��ȣ���Ц��һ�¡�\n",
        }) );
        set("inquiry", ([
                "����" : "�ҵ������ڻ����б�һ�����ĵ����ϵġ�\n",
                "leg" : "�ҵ������ڻ����б�һ�����ĵ����ϵġ�\n",
				"����":	"���Ӿ��ǳ���������Ļ���������ȥ�ˡ����ˣ����Ŵ�ʦ������ߣ�
��Ȼ��һ���͵��¡�\n",
				"���ĵ�": "��ʵ���Ĳ����ǵ��������õ����ˣ�������飬�ҵ�ס�����ĵ���ȴ����ס���Ļ�\n",
				"��":	"�ҿ��˼����Ψ�����������֮ˮ��������𣩵�����������ȥ�����Ļ�
����������ȴ�ֲ�ͬ����Ҫ�Զ��������Ի�Ի��С�\n",
				"�Զ�����":	"�Ҳ¡����������ĵ�ɱ��������\n",
				"�Ի�Ի�":	"�Ҳ¡����������ĵ�ɱ��������\n",
				"�����":"������������ڻ������е������ˡ�\n",
				"���":	"����ڹ�����ɽ���¡�\n",
				
	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}



int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
