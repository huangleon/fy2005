// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("�ϲ÷�", ({ "old dressmaker","dressmaker" }) );
	set("gender", "����" );
	set("title",HIR"���Ƶ�һ��"NOR);
	set("age", 65);
	set("long",
		"��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
        carry_object("/obj/armor/cloth")->wear();


        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/generate/common/basic_cloth_male"		  : 30,
                "obj/generate/common/basic_cloth_female"		  : 30,
                "obj/generate/common/basic_boots_male"		  : 30,
                "obj/generate/common/basic_boots_female"		  : 30,
                "obj/generate/common/basic_surcoat_male"		  : 30,
                "obj/generate/common/basic_surcoat_female"		  : 30,
                "obj/generate/common/basic_neck_male"		  : 30,
                "obj/generate/common/basic_neck_female"		  : 30,
                "obj/generate/common/basic_head_male"		  : 30,
                "obj/generate/common/basic_head_female"		  : 30,
                "obj/generate/common/basic_wrists"		  : 30,
        ]) );
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		
		// ż��֪�����ֵط��ϰ�������ߺ��˵>"<

        return;
}

void reset()
{
        set("vendor_goods", ([  
                "obj/generate/common/basic_cloth_male"		  : 30,
                "obj/generate/common/basic_cloth_female"		  : 30,
                "obj/generate/common/basic_boots_male"		  : 30,
                "obj/generate/common/basic_boots_female"		  : 30,
                "obj/generate/common/basic_surcoat_male"		  : 30,
                "obj/generate/common/basic_surcoat_female"		  : 30,
                "obj/generate/common/basic_neck_male"		  : 30,
                "obj/generate/common/basic_neck_female"		  : 30,
                "obj/generate/common/basic_head_male"		  : 30,
                "obj/generate/common/basic_head_female"		  : 30,
                "obj/generate/common/basic_wrists"		  : 30,
        ]) );
}


// ���p��dancing_faery@hotmail.com
